#include <stdio.h>
#include <stdlib.h>

int main () {
    float nota;

    printf ("ingresa tu nota:");
    scanf ("%d", &nota);

    if (nota <0 || nota >10) {
        printf ("Error, por favor ingrese unanota valida");
    } else if (nota < 4) {
        printf ("Estas reprobado\n");
    } else if (nota < 6) {
        printf ("Estas regular\n");
    } else (nota >= 6); {
        printf ("estas promocionado\n");
    }

    return 0;
}