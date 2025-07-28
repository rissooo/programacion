const readline = require ("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

rl.question("ingresa un numero: ", (imput) => {
    const numero = parseInt(imput);

    if (isNaN(numero)) {
        console.log("esto no es un numero")
    } else if (numero % 2 === 0) {
        console.log(`${numero} es un numero par`)
    } else {
        console.log(`${numero} es un numero impar`)
    }
    rl.close();
});
