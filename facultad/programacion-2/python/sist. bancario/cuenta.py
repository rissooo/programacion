class cuenta:
    def __init__(self, numero, titular, saldo=0):
        self.numero = numero
        self.titular = titular
        self.saldo = saldo
        
    def depositar(self, monto):
        if monto > 0:
            self.saldo += monto
            return True
        return False
    
    def retirar(self, monto):
        if 0 < monto <= self.saldo:
            self.saldo -= monto
            return True
        return False
    
    def transferir(self, monto, cuenta_destino):
        if self.retirar(monto):
            cuenta_destino.depositar(monto)
            return True
        return False
    
    