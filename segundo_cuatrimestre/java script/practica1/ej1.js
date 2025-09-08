const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question ("Ingrese su edad", (edad) => {
    if ((edad) >= 18) {
        console.log ("usted es mayor de edad")
    } else {
        console.log ("usted es menor de edad")
    }
    rl.close()
}); 