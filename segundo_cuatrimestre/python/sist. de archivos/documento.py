from datetime import datetime
from copy import copy
from Archivo import Archivo

class Documento(Archivo):
    def __init__(self, id, nombre, fecha, peso, contenido, fecha_de_creacion, fecha_de_modificacion):
        self.id = id
        self.nombre = nombre
        self.fecha = fecha
        self.peso = peso
        self.contenido = contenido
        self.peso = self.calcular_peso()
        self.fecha_de_creacion = fecha_de_creacion
        self.fecha_de_modificacion = fecha_de_modificacion
        
    def calcular_peso(self):
        bytes_cadena = self.contenido.encode("utf-8")  
        tamano_bytes = len(bytes_cadena)
        
    def __str__(self):
        return f"Documento: {self.nombre} ({self.peso} bytes)"
    
    def remover_elemento(self, elemento):
        if elemento in self.contenido:
            self.elementos.remove(elemento)
            
    def modificar_contenido(self, nuevo_contenido):
        self.contenido = nuevo_contenido
        self.peso = self.calcular_peso()
        self.fecha_modificacion = datetime.now()
        
    def renombrar(self, nuevo_nombre):
        self.nombre = nuevo_nombre
        self.fecha_modificacion = datetime.now()
        
    def tamano(self):
        return self.tamano
    
    def crear_copia(self):
        nueva_copia = copy.copy(self)           
        nueva_copia.id = None                   
        nueva_copia.nombre = f"Copia de {self.nombre}"
        nueva_copia.fecha_creacion = datetime.now()
        nueva_copia.fecha_modificacion = nueva_copia.fecha_creacion
        return nueva_copia