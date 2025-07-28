const readline = require ("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

let mayor = 0;
rl.question("ingrese un numero:", (input1) => {
    const numero1 = parseInt(input1);

    rl.question("ingresa el segundo numero:", (input2) => {
        const numero2 = parseInt(input2);

        if (isNaN(numero1) || isNaN(numero2)) {
            console.log ("ERROR: ingrese un numero valido")
        } else if (numero1 > numero2) {
            mayor = numero1;
            console.log (`el numero mayor es: ${numero1}`);
        } else {
            console.log (`el numero mayor es: ${numero2}`);
        }
        rl.close();
    });
});