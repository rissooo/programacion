const { NONAME } = require("dns");
const readline = require("readline");
const { Script } = require("vm");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function saludo (nombre) {
    console.log ("hola", nombre, "como estas hoy?")
}

console.log ("---menu---")
console.log ("ingrese:")
console.log ("1 para mostrar un saludo")
console.log ("2 para mostrar un saludo personalizado")
console.log ("3 para salir")

do {
switch (opcion) {
    case 1: 
    console.log ("hola, como has estado hoy?")
    break

    case 2: 
    console.log ("Ingresa tu nombre")
    saludo(nombre)
    
    case 3:
    console.log ("saliendo...")
    rl.close()
    }
} while (opcion != 3)