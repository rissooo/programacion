contactos = {}

while True:
    nombre = input("Ingrese el nombre: ")
    telefono = input("Ingrese el teléfono: ")

    if nombre in contactos:
        print(" Ese nombre ya existe, no se puede repetir.")
    else:
        contactos[nombre] = telefono
        print("Contacto agregado ")

    seguir = input("¿Desea agregar otro contacto? (si/no): ").lower()
    if seguir == "no":
        break

print("\n Agenda completa:")
print(contactos)