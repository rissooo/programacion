numero = int(input("ingrese un numero:\n"))

if numero < 0 :
    print(numero ,"es negativo")
elif numero > 0 :
    print(numero ,"es positivo")
else :
    print(numero, "es 0")

if numero % 2 == 0 :
    print(numero, "es par")
else :
    print(numero, "es impar")