import math

print("ingresa:\n")
print("1 para calcular area de un triangulo\n")
print("2 para clacular area de un cuadrado\n")
print("3 para calcular area de un rectangulo\n")
print("4 para cerrar el programa\n")

opcion = ""
match opcion:
    case 1: 
        a = float(input("ingresa el primer lado:\n"))
        b = float(input("ingresa el segundo lado:\n"))
        c = float(input("ingresa el tercer lado:\n"))
        
        s = (a + b + c) / 2
        
        area = math.sqrt(s * (s - a) * (s - b) * (s - c))
        
        print(f"el area del triangulo es:\n", {area})
    
    case 2:
        a = float(input("ingresa el lado:\n"))
        b = float(input("ingresa el segundo lado:\n"))
        
        area = a * b
        
        print("el area del cuadrado es:\n", {area})
        
    case 3:
        a = float(input("ingresa la altura:\n"))
        
        b = float(input("ingresa la base:\n"))
        
        area = b * a
        
        print("el area del rectangulo es:", {area})