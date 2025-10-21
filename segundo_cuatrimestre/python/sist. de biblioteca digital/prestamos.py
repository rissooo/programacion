from libros import Libro
from usuarios import Usuario

class Prestamos:
    def __init__(self, usuario: Usuario, libro: Libro, fecha_prestamo, fecha_devolucion):
        self.usuario = usuario
        self.libro = libro
        self.fecha_prestamo = fecha_prestamo
        self.fecha_devolucion = fecha_devolucion
        self.devuelto = False
        
    def marcar_como_devuelto(self):
        self.devuelto = True
        self.libro.disponible = True
        
    def mostrar_historial(self):
        return f"Usuario: {self.usuario.nombre}, Libro: {self.libro.nombre}, Fecha de Préstamo: {self.fecha_prestamo}, Fecha de Devolución: {self.fecha_devolucion}, Devuelto: {self.devuelto}"