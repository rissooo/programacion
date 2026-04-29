from cuenta import cuenta
from cuenta_corriente import CuentaCorriente

class CajaAhorro(cuenta):
    def __init__(self, numero, titular, saldo=0):
        super().__init__(numero, titular, saldo)
        
    def saldo_negativo(self):
        return self.saldo < 0