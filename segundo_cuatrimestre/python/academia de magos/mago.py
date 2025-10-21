class mago:
    def __init__(self, nombre, nivel_magia, energia):
        self.nombre = nombre
        self.nivel_magia = nivel_magia
        self.energia = energia
        
    def aprender_hechizo(self, hechizo):
        return f"{self.nombre} ha aprendido el hechizo {hechizo}."
    
    def lanzar_hechizo(self, hechizo, costo_energia):
        if self.energia >= costo_energia:
            self.energia -= costo_energia
            return f"{self.nombre} ha lanzado el hechizo {hechizo}."
        else:
            return f"{self.nombre} no tiene suficiente energía para lanzar el hechizo {hechizo}."
        
    def energia_insuficiente(self):
        return self.energia < 10
    
    def meditar(self, tiempo):
        recuperacion = tiempo * 5
        self.energia += recuperacion
        return f"{self.nombre} ha meditado por {tiempo} minutos y ha recuperado {recuperacion} de energía."
    
    