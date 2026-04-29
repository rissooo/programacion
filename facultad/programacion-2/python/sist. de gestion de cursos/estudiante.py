from curso import curso

class esudiante:
    def __init__(self, nombre, email, notas):
        self.nombre = nombre
        self.email = email
        self.notas = notas
        
    def registrar_nota(self, curso: curso, nota):
        self.notas[curso.nombre] = nota
        
    