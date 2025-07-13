#include <stdio.h>
#include <string.h>
#define max 10
void cargaDatos (float precio[max], char nombre[max][30], int cantidad) {
        int i = 0;
        do {
        printf ("ingrese el nombre del producto/n");
        scanf ("%c", &nombre[i]);

        do {
        printf ("ingresa el precio del producto/n");
        scanf ("%f", &precio[i]);
        if (precio[i] < 0) {
            printf ("ERROR: ingrese un precio valido/n");
        }
        } while (precio[i] <= 0);

        char seguir;
        printf ("usted desea seguir ingresando? (si/no):");
        scanf ("%c", &seguir);
        if (seguir != "si" && seguir != "SI"){
            break;
        }

        } while ( i < max);
        cantidad = i; 
}

void calculos ( float precio[max], char nombre[max][30], float mayor, float total, float promedio) {
    mayor = precio[0];
    total = 0;
    for (int i = 0; i < max; i++) {
        total += precio[i];
        if (precio[i] > mayor) {
            mayor = precio[i];
        }
    }
    promedio = total/max;
}


  