class curso:
    def __init__(self, nombre, profesor, lista_estudiantes):
        self.nombre = nombre
        self.profesor = profesor
        self.lista_estudiantes = lista_estudiantes
        
    def agregar_estudiante(self, estudiante):
        self.lista_estudiantes.append(estudiante)
        
    def registrar_notas(self, estudiante, nota):
        estudiante.registrar_nota(self, nota)
        
    def calcular_promedio(self):
        total = 0
        for estudiante in self.lista_estudiantes:
            total += estudiante.notas.get(self.nombre, 0)
        return total / len(self.lista_estudiantes) if self.lista_estudiantes else 0
    
    def ranking_estudiantes(self):
        return sorted(self.lista_estudiantes, key=lambda est: est.notas.get(self.nombre, 0), reverse=True)

    def limitar_cupo(self, max_estudiantes):
        max_estudiantes = 11
        if len(self.lista_estudiantes) > max_estudiantes:
            self.lista_estudiantes = self.lista_estudiantes[:max_estudiantes]