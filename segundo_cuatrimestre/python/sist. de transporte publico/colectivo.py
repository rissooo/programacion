from linea import Linea
from pasajero import Pasajero

class Colectivo:
    def __init__(self, interno, chofer_asignado, capacidad, pasajeros_actuales, recaudacion):
        self.interno = interno
        self.chofer_asignado = chofer_asignado
        self.capacidad = capacidad
        self.pasajeros_actuales = pasajeros_actuales
        self.recaudacion = recaudacion
        
    def lleno(self):
        return len(self.pasajeros_actuales) >= self.capacidad
    