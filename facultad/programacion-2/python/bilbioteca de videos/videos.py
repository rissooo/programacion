from datetime import datetime 
from playlist import playlist

class videos:
    def __init__(self, titulo, fecha, duracion, creador, fecha_subida, hora_de_subida):
        self.titulo = titulo
        self.fecha = fecha
        self.duracion = duracion
        self.creador = creador
        self.fecha_subida = fecha_subida
        self.hora_de_subida = hora_de_subida
        self.fecha_eliminacion = None  
        
    @property
    def titulo(self):
        if self.fecha_eliminacion:
            return "este video fue eliminado"
        return self.titulo
    
    def eliminar_video(self):
        self.fecha_eliminacion = datetime.now()
        
    @titulo.setter
    def titulo(self, valor):
        self._titulo = valor