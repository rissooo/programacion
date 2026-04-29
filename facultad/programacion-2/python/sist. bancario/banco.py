from cuenta import Cuenta
from cuenta_corriente import CuentaCorriente
from caja_ahorro import CajaAhorro

class Banco:
    def __init__(self, cuentas=None):
        if cuentas is None:
            cuentas = []
        self.cuentas = cuentas
        
    def buscar_cuenta_por_titular(self, titular):
        for cuenta in self.cuentas:
            if cuenta.titular == titular:
                return cuenta
        return None
    
    def resumen_fondos(self):
        resumen = {}
        for cuenta in self.cuentas:
            resumen[cuenta.titular] = cuenta.saldo
        return resumen