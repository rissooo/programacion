class bateria_vacia:
    def __init__(self, bateria_vacia):
        self.bateria_vacia = bateria_vacia
        
class bateria_llena:
    def __init__(self, bateria_llena):
        self.bateria_llena = bateria_llena
        
class linterna(bateria_vacia):
    def __init__(self, bateria_vacia):
        super().__init__(bateria_vacia)
        
        print("la linterna no funciona porque la bateria esta vacia")

class linterna_que_funciona(bateria_llena):
    def __init__(self, bateria_llena):
        super().__init__(bateria_llena)
        
        print("la linterna funciona porque la bateria esta llena")
        
linterna1 = linterna()
linterna2 = linterna_que_funciona()