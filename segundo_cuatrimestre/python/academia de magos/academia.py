from mago import mago
from hechizos import hechizo

class academia:
    def __init__(self, magos):
        self.magos = []
        
    def agregar_mago(self, mago):
        self.magos.append(mago)
        
    def mas_poderoso(self):
        if not self.magos:
            return None
        return max(self.magos, key=lambda m: m.nivel_magia)
    
    def listar_magos(self):
        return [f"{mago.nombre} (Nivel de Magia: {mago.nivel_magia}, Energía: {mago.energia})" for mago in self.magos]