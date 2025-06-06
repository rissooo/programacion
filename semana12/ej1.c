#include <stdio.h>
#include <stdlib.h>

char mensajeBienvendia (char primerainicial) {
    printf("Bienvenido %c\n", primerainicial);
    return primerainicial;
}

int main() {
    char inicial;

    printf("Ingrese la inicial de su nombre: ");
    scanf(" %c", &inicial);

    mensajeBienvendia(inicial);

    return 0;
}