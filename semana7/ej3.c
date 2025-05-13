#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int lado1;
    int lado2;
    float hipotenusa;
    float perimetro;
    float superficie;

    printf ("ingrese un lado:");
    scanf ("%d", &lado1);

    printf ("ingrese otro lado:");
    scanf ("%d", &lado2);

    hipotenusa = sqrt(pow(lado1, 2)) + pow(lado2, 2);
    perimetro = lado1 + lado2;
    superficie = lado1 * lado2;

    printf ("La hipotenusa es %f\n", hipotenusa);
    printf ("El perimetro es %f\n", perimetro);
    printf ("La superficie es %f\n", superficie);

    getchar();

    return 0;
}