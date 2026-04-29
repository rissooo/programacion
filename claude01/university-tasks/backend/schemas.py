from pydantic import BaseModel, field_validator, EmailStr, Field
from typing import Literal, Optional
from datetime import datetime, date


# ── Auth ─────────────────────────────────────────────────────────────────────

class UserCreate(BaseModel):
    email: EmailStr
    password: str = Field(min_length=8, max_length=128)


class UserLogin(BaseModel):
    email: EmailStr
    password: str = Field(min_length=1, max_length=128)


class Token(BaseModel):
    access_token: str
    token_type: str


class UserResponse(BaseModel):
    id: int
    email: str

    model_config = {"from_attributes": True}


# ── Tasks ─────────────────────────────────────────────────────────────────────

class TaskCreate(BaseModel):
    name: str = Field(min_length=1, max_length=255)
    description: str = Field(min_length=1, max_length=2000)
    due_date: date

    @field_validator("name", "description")
    @classmethod
    def not_empty(cls, v: str) -> str:
        if not v or not v.strip():
            raise ValueError("Field cannot be empty")
        return v.strip()


class TaskUpdate(BaseModel):
    name: Optional[str] = Field(None, min_length=1, max_length=255)
    description: Optional[str] = Field(None, min_length=1, max_length=2000)

    @field_validator("name", "description", mode="before")
    @classmethod
    def not_empty_if_provided(cls, v):
        if v is not None and not str(v).strip():
            raise ValueError("Field cannot be empty")
        return v


class TaskStatusUpdate(BaseModel):
    status: Literal["pending", "completed"]


class TaskResponse(BaseModel):
    id: int
    name: str
    description: str
    status: str
    due_date: Optional[date]
    created_at: datetime

    model_config = {"from_attributes": True}


class TrashTaskResponse(BaseModel):
    id: int
    name: str
    description: str
    status: str
    due_date: Optional[date]
    deleted_at: datetime
    days_remaining: int

    model_config = {"from_attributes": True}
