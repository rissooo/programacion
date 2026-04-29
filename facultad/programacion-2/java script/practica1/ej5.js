const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let clave = Franxd
    rl.question ("Ingrese la contraseña", (contraIngresada) => {
        do {
        if (contraIngresada = clave) {
            console.log ("Felicidades pudo ingresar")
        } else if (contraIngresada != clave) {
            console.log ("Esa no es la clave, reintentelo")
        }
        } while (contraIngresada != clave)
    })