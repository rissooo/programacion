from vehiculo import vehiculo

class moto(vehiculo):
    def __init__(self, marca, modelo, anio, valor, cilindrada):
        super().__init__(marca, modelo, anio, valor, cilindrada)
        self.cilindrada = cilindrada
        
        def calcular_impuesto(self):
            return self.valor * 0.03