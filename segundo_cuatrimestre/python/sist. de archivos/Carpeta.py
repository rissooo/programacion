from datetime import datetime
from copy import copy
from Archivo import Archivo

class Carpeta(Archivo):
    def __init__(self, id, nombre, fecha, hora_de_creacion):
        self.id = id
        self.nombre = nombre
        self.fecha = fecha
        self.elementos = []
        self.hora_de_creacion = hora_de_creacion
        
    def guardar(self, elementos):
        self.elementos.append(elementos)
        
    def remover_elemento(self, elemento):
        if elemento in self.contenido:
            self.elementos.remove(elemento)
            
    def tamano(self):
        total_bytes = 0
        for elementos in self.elementos:
            total_bytes += elementos.tamano()
        return total_bytes / 1024
    
    def vaciar_lista(self):
        self.contenido.clear()