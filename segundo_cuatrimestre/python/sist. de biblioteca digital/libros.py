from prestamos import Prestamo
from usuarios import Usuario

class Libro:
    def __init__(self, nombre, autor, genero):
        self.nombre = nombre
        self.autor = autor
        self.genero = genero
        self.disponible = True
        
    def libro_prestado(self):
        self.disponible = False