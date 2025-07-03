#include <stdio.h>
#define max 50

typedef struct {
    char nombre[30];
    int stock;
    float precio;
} Producto;

void carga (float productos[max]) {
    for (int i = 0; i < max; i++) {
        printf ("ingrese un nombre del pruducto/n");
        scanf ("%f", &productos[i]);
    }
}