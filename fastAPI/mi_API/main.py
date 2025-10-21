from fastapi import FastAPI, Request, HTTPException
from pydantic import BaseModel
from fastapi.templating import Jinja2Templates
from fastapi.responses import HTMLResponse
from fastapi.staticfiles import StaticFiles
import json
import os
import time

app = FastAPI(title="Gestor de Tareas", version="1.0.0")
templates = Jinja2Templates(directory="templates")
app.mount("/static", StaticFiles(directory="static"), name="static")

RUTA_ARCHIVO = "tareas.json"

def cargar_tareas():
    if os.path.exists(RUTA_ARCHIVO):
        with open(RUTA_ARCHIVO, "r", encoding="utf-8") as f:
            return json.load(f)
    return [] 

def guardar_tareas():
    with open(RUTA_ARCHIVO, "w", encoding="utf-8") as f:
        json.dump(tareas, f, ensure_ascii=False, indent=2)

@app.get("/", response_class=HTMLResponse)
def home(request: Request):
    return templates.TemplateResponse("index.html", {"request": request, "Nombre": "Francisco"})

class TareaBase(BaseModel):
    titulo: str
    completada: bool = False


class TareaCreate(TareaBase):
    id: int | None = None


class Tarea(TareaBase):
    id: int


tareas: list[dict] = cargar_tareas()


@app.post("/tareas", response_model=Tarea, status_code=201)
def crear_tarea(tarea: TareaCreate):
    nuevo_id = tarea.id
    if nuevo_id is None:
        # Genera un id basado en timestamp en ms y evita colisiones simples
        nuevo_id = int(time.time() * 1000)
        while any(t["id"] == nuevo_id for t in tareas):
            nuevo_id += 1
    elif any(t["id"] == nuevo_id for t in tareas):
        raise HTTPException(status_code=400, detail="El id ya existe")

    nuevo = {"id": nuevo_id, "titulo": tarea.titulo, "completada": tarea.completada}
    tareas.append(nuevo)
    guardar_tareas()
    return nuevo

@app.put("/tareas/{id}", response_model=Tarea)
def actualizar_tarea(id: int, nueva_tarea: TareaBase):
    for t in tareas:
        if t["id"] == id:
            t["titulo"] = nueva_tarea.titulo
            t["completada"] = nueva_tarea.completada
            guardar_tareas()
            return t
    raise HTTPException(status_code=404, detail="Tarea no encontrada")

@app.delete("/tareas/{id}", status_code=204)
def eliminar_tarea(id: int):
    for t in tareas:
        if t["id"] == id:
            tareas.remove(t)
            guardar_tareas()
            return
    raise HTTPException(status_code=404, detail="Tarea no encontrada")

@app.get("/tareas", response_model=list[Tarea])
def listar_tareas():
    return tareas


@app.get("/tareas/{id}", response_model=Tarea)
def obtener_tarea(id: int):
    for t in tareas:
        if t["id"] == id:
            return t
    raise HTTPException(status_code=404, detail="Tarea no encontrada")


@app.get("/health")
def health():
    return {"status": "ok"}
