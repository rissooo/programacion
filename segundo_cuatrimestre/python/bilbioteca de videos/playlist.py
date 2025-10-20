from datetime import datetime, timedelta
from videos import videos

class playlist:
    def __init__(self, nombre, creador):
        self.nombre = nombre
        self.creador = creador
        self.videos = []
        
    def agregar_video(self, video):
        self.videos.append(video)
        
    def eliminar_video(self, video):
        if video in self.videos:
            video.eliminar()
        else:
            print("El video no está en la playlist.")
        
    def ordenar_videos(self):
        self.videos.sort()
        
    def cantidad_videos(self):
        return len(self.videos)
    
    def tiempo_total_de_reproduccion(self):
        total_minutos = sum(video.duracion for video in self.videos)
        horas, minutos = divmod(total_minutos, 60)
        return "f{horas:02}:{minutos:02}"