class  articulo:
    def __init__(self, nombre, costo):
        self.nombre = nombre
        self.costo = costo
        
    def descripcion (self):
        return f"item: {self.nombre}, {self.costo}"