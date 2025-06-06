#include <stdio.h>
#include <stdlib.h>

float cuboNumeroReal (float num) {
    return num * num * num;
} 

int main () {
    float num;

    printf("Ingrese un numero real: ");
    scanf("%f", &num);

    printf("El cubo del numero %.2f es: %.2f\n", num, cuboNumeroReal(num));

    return 0;
}