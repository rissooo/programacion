from vehiculo import vehiculo

class camion_carga(vehiculo):
    def __init__(self, marca, modelo, anio, capacidad_carga, valor):
        super().__init__(marca, modelo, anio,)
        self.capacidad_carga = capacidad_carga
        self.valor = valor
        
    def impuesto_anual(self):
        return self.valor * 0.10