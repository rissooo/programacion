const { NONAME } = require("dns");
const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function calcularArea (base, altura, area) {
    return area = base * altura
}

rl.question ("ingrese la altura\n", (altura) => {
    rl.question ("ingrese la base\n", (base) => {
        console.log ("el area es", calcularArea(altura, base))
        rl.close()
    })
})