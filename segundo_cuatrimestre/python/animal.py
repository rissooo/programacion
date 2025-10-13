class animal:
    def __init__(self, se_alimenta, reino_animal, respiran, sonido):
        self.se_alimenta = se_alimenta
        self.reino_animal = reino_animal
        self.respiran = respiran
        self.sonido = sonido
        
        print("el animal hizo un sonido")
        
class perro(animal):
        def __init__ (self, se_alimenta, reino_animal, respiran, sonido, amo):
            super().__init__(se_alimenta, reino_animal, respiran, sonido)
            self.amo = amo
            
            print("el perro ladra")
            
