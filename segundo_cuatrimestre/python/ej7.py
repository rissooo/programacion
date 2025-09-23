nombre = input("Ingrese su nombre:\n")
edad = int(input("ingrese su edad:\n"))
ciudad = input("ingrese su ciudad de residencia:\n")
año = int(input("ingrese su año de nacimiento:\n"))

if edad < 18 : 
    print("Usted es menor de edad")
else :
    print("usted es mayor de edad")

if edad % 5 == 0 :
    print("su edad es multiplo de 5")
else :
    print("su edad no es multiplo de 5")

lista = [nombre, edad, ciudad, año]

print(lista)