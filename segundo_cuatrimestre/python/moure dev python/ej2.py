palabra1 = input("Ingresa la primer palabra\n")
sorted(palabra1)

palabra2 = input("Ingresa la segunda palabra\n")
sorted(palabra2)

if palabra1 == palabra2:
    print("No es un anagrama, son iguales")
elif sorted(palabra1) == sorted(palabra2):
    print("Es un anagrama")
else:
    print("No es un anagrama")