const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function par (num) {
    if (num % 2 === 0) {
        console.log ("es par")
    } else {
        console.log ("es impar")
    }
}

rl.question ("Ingrese un numero", (num) => {
    num = Number(num)
    console.log ("el numero", par(num))
    rl.close()
})