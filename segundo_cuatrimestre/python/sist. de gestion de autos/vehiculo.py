class vehiculo:
    def __init__(self, marca, modelo, anio, valor):
        self.marca = marca
        self.modelo = modelo
        self.anio = anio
        self.valor = valor
        
    def acelearar(self):
        return f"El vehículo {self.marca} {self.modelo} está acelerando."
    
    def frenar(self):
        return f"El vehículo {self.marca} {self.modelo} está frenando."
    
    def mostrar_info(self):
        return f"Marca: {self.marca}, Modelo: {self.modelo}, Año: {self.anio}, valor: {self.valor}"
    
    def calcular_impuesto(self):
        pass