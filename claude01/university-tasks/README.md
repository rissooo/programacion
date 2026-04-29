# University Task Manager

A full-stack task management app for students. Built with Vue 3, FastAPI, and PostgreSQL.

## Stack

| Layer    | Technology                          |
|----------|-------------------------------------|
| Frontend | Vue 3, Composition API, Pinia, Vite, TailwindCSS |
| Backend  | FastAPI (Python 3.11)               |
| Database | PostgreSQL 15                       |
| Dev Env  | Docker Compose                      |

## Quick Start

```bash
cd university-tasks
docker compose up --build
```

That's it. All three services start automatically.

## URLs

| Service      | URL                            |
|--------------|--------------------------------|
| Frontend     | http://localhost:5173          |
| Backend API  | http://localhost:8000          |
| API Docs     | http://localhost:8000/docs     |

## Features

- Create tasks with a name and description (both required)
- Mark pending tasks as completed (green checkmark button)
- Move completed tasks back to pending (gray button — auto-navigates to pending section)
- Delete any task (red X button)
- Collapsible pending / completed sections with live counts
- All data persisted in PostgreSQL
- Hot-reload for both frontend and backend

## API Endpoints

| Method | Path                      | Description             |
|--------|---------------------------|-------------------------|
| GET    | /api/tasks                | List all tasks          |
| GET    | /api/tasks?status=pending | Filter by status        |
| POST   | /api/tasks                | Create a task           |
| PATCH  | /api/tasks/{id}/status    | Update task status      |
| DELETE | /api/tasks/{id}           | Delete a task           |

## Stopping

```bash
docker compose down
```

To also remove the database volume:

```bash
docker compose down -v
```
