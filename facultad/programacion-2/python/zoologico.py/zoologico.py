from animal import Animal
from mamimero import mamifero

class zoologico:
    def __init__(self, nombre):
        self.nombre = nombre
        self.animales = []
    
    def agregar_animal(self, animal):
        self.animales.append(animal)
    
    def listar_animales(self):
        return [f"{animal.nombre} ({animal.especie})" for animal in self.animales]
    
    def alimentar_mamiferos(self):
        return [animal.comer() for animal in self.animales if isinstance(animal, mamifero)]