#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 5
#define maxNombres 50

void cargaDatos (float precio[max], char nombres[max][maxNombres]) {
    for (int i = 0; i < max; i++) {
        printf ("ingrese nombre del juego-%d\n", i + 1);
        scanf ("%49s", nombres[i]);

        printf ("ingrese precio del juego%d\n", i + 1);
        scanf ("%f", &precio[i]);

        if (precio[i] <= 0) {
            printf ("ERROR: ingrese un valor valido\n");
            i--;
        }
    }
}

int buscarJuego (float precio[max], char nombres[max][maxNombres], char buscar[maxNombres]) {
    for (int i = 0; i < max; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("El juego '%s' cuesta $%.2f\n", nombres[i], precio[i]);
            return i;
        }
    }
    printf ("No se encontro ese juego en el catalogo\n");
    return -1;
}

void mostrarLista (float precio[max], char nombres[max][maxNombres]) {
    printf ("Este es el catalogo\n");
    for (int i = 0; i < max; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precio[i]);
    }
}

void mostrarMenu () {
    int opcion;
    float precio[max];
    char nombres[max][maxNombres];
    char buscar[maxNombres];

    do {

    printf ("---Bienvenido Sistema de Gestión de Precios de Juegos---\n");
    printf ("Ingrese:\n");
    printf ("1 para cargar nombres de juegos y su precio\n");
    printf ("2 para buscar el nombre del juego en el catalogo\n");
    printf ("3 para ver todo el catalogo\n");
    printf ("4 para terminar el programa\n");
    scanf ("%d", &opcion);

        switch (opcion) {
            case 1: 
            cargaDatos (precio, nombres);
            break;

            case 2:
            printf ("Ingrese el nombre del juego que quiere buscar\n");
            scanf ("%49s", buscar);
            buscarJuego (precio, nombres, buscar);
            break;

            case 3:
            mostrarLista (precio, nombres);
            break;

            case 4:
            printf ("El programa se esta cerro\n");
            break;
        }
    } while (opcion != 4);
}

int main () {
    mostrarMenu ();

    return 0;
}