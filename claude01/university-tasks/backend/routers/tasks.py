import logging
from fastapi import APIRouter, Depends, HTTPException, Query
from sqlalchemy.orm import Session
from typing import List, Optional
from datetime import datetime, timezone, timedelta
from database import get_db
from models import Task, User
from schemas import TaskCreate, TaskStatusUpdate, TaskResponse, TrashTaskResponse
from auth import get_current_user

logger = logging.getLogger(__name__)
router = APIRouter(prefix="/api/tasks", tags=["tasks"])

TRASH_EXPIRY_DAYS = 30


def _purge_expired(db: Session, user_id: int):
    cutoff = datetime.now(timezone.utc).replace(tzinfo=None) - timedelta(days=TRASH_EXPIRY_DAYS)
    db.query(Task).filter(
        Task.user_id == user_id,
        Task.deleted_at.isnot(None),
        Task.deleted_at < cutoff,
    ).delete()
    db.commit()


def _days_remaining(deleted_at: datetime) -> int:
    now = datetime.now(timezone.utc).replace(tzinfo=None)
    deleted = deleted_at.replace(tzinfo=None) if deleted_at.tzinfo else deleted_at
    expires = deleted + timedelta(days=TRASH_EXPIRY_DAYS)
    return max(0, (expires - now).days)


# ── Active tasks ──────────────────────────────────────────────────────────────

@router.get("", response_model=List[TaskResponse])
def get_tasks(
    status: Optional[str] = Query(None, pattern="^(pending|completed)$"),
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    query = db.query(Task).filter(Task.user_id == current_user.id, Task.deleted_at.is_(None))
    if status:
        query = query.filter(Task.status == status)
    return query.order_by(Task.created_at.desc()).all()


@router.post("", response_model=TaskResponse, status_code=201)
def create_task(
    payload: TaskCreate,
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    task = Task(
        user_id=current_user.id,
        name=payload.name,
        description=payload.description,
        due_date=payload.due_date,
    )
    db.add(task)
    db.commit()
    db.refresh(task)
    logger.info(f"Task created id={task.id} by user_id={current_user.id}")
    return task


@router.patch("/{task_id}/status", response_model=TaskResponse)
def update_task_status(
    task_id: int,
    payload: TaskStatusUpdate,
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    task = db.query(Task).filter(
        Task.id == task_id,
        Task.user_id == current_user.id,
        Task.deleted_at.is_(None),
    ).first()
    if not task:
        raise HTTPException(status_code=404, detail="Task not found")
    task.status = payload.status
    db.commit()
    db.refresh(task)
    logger.info(f"Task id={task_id} status={payload.status} by user_id={current_user.id}")
    return task


@router.delete("/{task_id}", status_code=204)
def soft_delete_task(
    task_id: int,
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    task = db.query(Task).filter(
        Task.id == task_id,
        Task.user_id == current_user.id,
        Task.deleted_at.is_(None),
    ).first()
    if not task:
        raise HTTPException(status_code=404, detail="Task not found")
    task.deleted_at = datetime.now(timezone.utc).replace(tzinfo=None)
    db.commit()
    logger.info(f"Task id={task_id} soft-deleted by user_id={current_user.id}")


# ── Trash ─────────────────────────────────────────────────────────────────────

@router.get("/trash", response_model=List[TrashTaskResponse])
def get_trash(
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    _purge_expired(db, current_user.id)
    tasks = (
        db.query(Task)
        .filter(Task.user_id == current_user.id, Task.deleted_at.isnot(None))
        .order_by(Task.deleted_at.desc())
        .all()
    )
    return [
        TrashTaskResponse(
            id=t.id,
            name=t.name,
            description=t.description,
            status=t.status,
            due_date=t.due_date,
            deleted_at=t.deleted_at,
            days_remaining=_days_remaining(t.deleted_at),
        )
        for t in tasks
    ]


@router.post("/trash/{task_id}/restore", response_model=TaskResponse)
def restore_task(
    task_id: int,
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    task = db.query(Task).filter(
        Task.id == task_id,
        Task.user_id == current_user.id,
        Task.deleted_at.isnot(None),
    ).first()
    if not task:
        raise HTTPException(status_code=404, detail="Task not found in trash")
    task.deleted_at = None
    db.commit()
    db.refresh(task)
    logger.info(f"Task id={task_id} restored by user_id={current_user.id}")
    return task


@router.delete("/trash/{task_id}", status_code=204)
def permanent_delete_task(
    task_id: int,
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    task = db.query(Task).filter(
        Task.id == task_id,
        Task.user_id == current_user.id,
        Task.deleted_at.isnot(None),
    ).first()
    if not task:
        raise HTTPException(status_code=404, detail="Task not found in trash")
    db.delete(task)
    db.commit()
    logger.info(f"Task id={task_id} permanently deleted by user_id={current_user.id}")


@router.delete("/trash", status_code=204)
def empty_trash(
    db: Session = Depends(get_db),
    current_user: User = Depends(get_current_user),
):
    db.query(Task).filter(Task.user_id == current_user.id, Task.deleted_at.isnot(None)).delete()
    db.commit()
    logger.info(f"Trash emptied by user_id={current_user.id}")
