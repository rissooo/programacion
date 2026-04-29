from pasajero import Pasajero
from colectivo import Colectivo

class Linea:
    def __init__(self, numero_linea, lista_colectivos):
        self.numero_linea = numero_linea
        self.lista_colectivos = lista_colectivos
        
    def recaucion_total(self):
        total = 0
        for colectivo in self.lista_colectivos:
            total += colectivo.recaudacion
        return total
    
    def lista_colectivos(self):
        return self.lista_colectivos