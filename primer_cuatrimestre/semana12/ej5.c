#include <stdio.h>
#include <stdlib.h>

int signo (int num) {
    if (num > 0) {
        return 1; 
    } else if (num < 0) {
        return -1; 
    } else {
        return 0;
    }
}

int main () {
    int num;
    int resultado;

    printf("Ingrese un numero: "); 
    scanf("%d", &num);

    resultado = signo(num);

    if (resultado == 1) {
        printf("El numero es positivo.\n");
    } else if (resultado == -1) {
        printf("El numero es negativo.\n");
    } else {
        printf("El numero es cero.\n");
    }

    return 0;
}