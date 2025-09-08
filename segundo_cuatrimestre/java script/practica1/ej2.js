const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question ("ingrese un numero", (num) => {
  num = number(num)
    if ((num) > 0) {
      console.log (num, "es positivo")
    } if ((num) < 0) {
      console.log (num, "es negativo")
    } if ((num) === 0) {
      console.log ("el numero es 0")
    }
})