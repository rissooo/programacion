from libros import Libro
from prestamos import Prestamo

class Usuarios:
    def __init__(self, nombre, correo, lista_prestamos=None):
        self.nombre = nombre
        self.correo = correo
        if lista_prestamos is None:
            self.lista_prestamos = []
        else:
            self.lista_prestamos = lista_prestamos
            
    