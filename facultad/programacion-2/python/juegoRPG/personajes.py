from habilidades import habilidades
import random
class personajes:
    def __init__(self, nombre, nivel, puntos_disponibles, hablidad_inicial):
        self.nombre = nombre
        self.nivel = nivel
        self.puntos_disponibles = puntos_disponibles
        self.habilidad_inicial = hablidad_inicial
        self.lista_habilidades = []
        
    def subir_nivel(self):
        self.nivel += 1
        
    def elegir_entre_tres(self, aire, hielo, fuego):
        return random.choice([aire, hielo, fuego])
    
    def desbloquear_habilidad(self, nueva_habilidad):
        if self.puntos_disponibles >= nueva_habilidad.costo_puntos:
            self.lista_habilidades.append(nueva_habilidad)
            self.puntos_disponibles -= nueva_habilidad.costo_puntos
            return True
        else:
            return False