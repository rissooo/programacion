from animal import Animal

class mamifero(Animal):
    def __init__(self, nombre, especie, edad):
        super().__init__(nombre, especie, edad)
        
    def amamantar(self):
        return f"{self.nombre} está amamantando a sus crías."
    
    def comer(self):
        return f"{self.nombre} está comiendo alimento para mamíferos."