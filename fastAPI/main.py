from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def read_root():
    return {"mensaje": "Hola desde FastAPI!"}

@app.get("/users/{gato}")
async def get_users(id, gato):
    return{"id": id}
