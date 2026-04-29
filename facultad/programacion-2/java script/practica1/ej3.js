const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question ("ingrese el primer numero", (num1) =>  {
    num1 = number(num1)
    rl.question ("ingrese el segundo numero", (num2) => {
        num2 = number(num2)
        if ((num1) > (num2)) {
            console.log ("el mayor es", num1)
        } else if ((num1) < (num2)) {
            console.log ("el mayor es", num2)
        } else  {
            console.log ("son iguales")
        }
    })
})