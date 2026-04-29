const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question ("Ingrese un precio", (precio) => {
    let total = 0
    if ((precio) > 1000) {
        let total = precio * 0.9
    }
    console.log (total)
})