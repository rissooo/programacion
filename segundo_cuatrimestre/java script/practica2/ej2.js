const { clear } = require("console");
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function doble (num) {
    return total = num * 2
}

rl.question ("ingrese un numero", (num) => {
    num = Number(num)
    console.log ("el doble es", doble(num))
    rl.close()
})

