from cuenta import Cuenta

class CuentaCorriente(Cuenta):
    def __init__(self, numero, titular, saldo=0, descubierto=0):
        super().__init__(numero, titular, saldo)
        self.descubierto = descubierto
        
    def retirar(self, monto):
        if monto > 0 and monto <= self.saldo + self.descubierto:
            self.saldo -= monto
            return True
        return False