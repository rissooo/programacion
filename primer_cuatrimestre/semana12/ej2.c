#include <stdio.h>
#include <stdlib.h>

int calcularAreaCuadrado (int lado) {
    return lado * lado;
}

int main () {
    int lado;
    printf("Ingrese el lado del cuadrado: ");
    scanf("%d", &lado);
    
    printf("El área del cuadrado es: %d\n", calcularAreaCuadrado(lado));
    
    return 0;
}