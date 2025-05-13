#include <stdio.h>

void main() {
    float altura;

    printf ("Ingrese su altura:\n");
    scanf ("%f", &altura);

    if (altura <= 150) {
        printf ("Persona con altura por debajo de la media\n");
    } else if (altura > 150 && altura < 170) {
        printf ("Persona con altura promedio\n");
    } else {
        printf ("persona con altura por encima del promedio\n");
    }
}