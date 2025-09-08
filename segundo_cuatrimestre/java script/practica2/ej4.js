const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function saludo (nombre) {
    console.log ("hola", nombre, "como estas hoy?")
}

rl.question ("Ingrese un nombre") 