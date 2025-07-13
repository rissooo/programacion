#include <stdio.h>
#include <stdlib.h>

void main() {
    int mes;
    printf ("Ingrese un numero del 1 al 12\n");
    scanf ("%d", &mes);

    if (mes == 1) {
        printf ("Enero\n");
    } else if (mes == 2) {
        printf ("Febrero\n");
    } else if (mes == 3) {
        printf ("Marzo\n"); 
    } else if (mes == 4) {
        printf ("Abril\n");
    } else if (mes == 5) {
        printf ("Mayo\n");
    } else if (mes == 6) {
        printf ("junio\n");
    } else if (mes == 7) {
        printf ("Julio\n");
    } else if (mes == 8) {
        printf ("Agosto\n");
    } else if (mes == 9) {
        printf ("septiembre\n");
    } else if (mes == 10) {
        printf ("octubre\n");
    } else if (mes == 11) {
        printf ("noviembre\n");
    } else if (mes == 12) {
        printf ("Diciembre\n");
    } else {
        printf ("Ingrese un numero valido");
    }
}