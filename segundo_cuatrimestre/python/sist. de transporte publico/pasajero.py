class Pasajero:
    def __init__(self, nombre, tarjeta_sube, saldo):
        self.nombre = nombre
        self.tarjeta_sube = tarjeta_sube
        self.saldo = saldo
        
    def saldo_actual(self):
        return self.saldo
    
    def saldo_insuficiente(self, costo_viaje):
        return self.saldo < costo_viaje
    
    