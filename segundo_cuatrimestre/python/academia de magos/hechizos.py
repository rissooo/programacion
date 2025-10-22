from mago import mago

class hechizo:
    def __init__(self, nombre, nivel_requerido, costo_energia):
        self.nombre = nombre
        self.nivel_requerido = nivel_requerido
        self.costo_energia = costo_energia
        
    def es_aprendible(self, mago):
        return mago.nivel_magia >= self.nivel_requerido
    
    def descripcion(self):
        return f"Hechizo: {self.nombre}, Nivel Requerido: {self.nivel_requerido}, Costo de Energía: {self.costo_energia}"
    
    