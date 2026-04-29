from vehiculo import vehiculo

class auto(vehiculo):
    def __init__(self, marca, modelo, anio, valor, puertas):
        super().__init__(marca, modelo, anio, valor)
        self.puertas = puertas
        
    def calcular_impuesto(self):
        return self.valor * 0.05