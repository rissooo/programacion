#include <stdio.h>
#include <stdlib.h>
#define max 50

int carga (float precio[max]) {
    for (int i; i < max; i++) {
        printf ("ingrese el precio del producto:\n", i + 1);
        scanf ("%f", &precio[i]);

        if (precio[i] < 0) {
            printf ("ERROR: ingrese un valor mayor a 0\n");
        }
    }
}

void calculos (float precio[max], int cantidad) {
    float mayor = precio[0];
    float menor = precio[0];
    int posicion_mas_barato = 0;
    float promedio;
    float total = 0;
    int productos_menos_promedio = 0;

    for (int i = 0; i < max; i++) {
        total += precio[i];

        if (mayor < precio[i]) {
            mayor = precio[i];
        }

        if (menor > precio[i]) {
            menor = precio[i];
            posicion_mas_barato = i;
        }
    }
    promedio = total/cantidad;

    for (int i = 0; i < max; i++) {
        if (precio[i] < promedio) {
            productos_menos_promedio++;
        }
    }

    printf ("resultados\n");
    printf ("el mayor es: %f\n", mayor);
    printf ("el menor es: %f\n", menor);
    printf ("la posicion del mas barato es: %d\n", posicion_mas_barato);
    printf ("el promedio es: %f\n", promedio);
    printf ("los productos que estan por debajo del promedio son: %d\n", productos_menos_promedio);
}

int main () {
    float precio[max];
    int cantidad;

    cantidad = carga(precio);
    calculos(precio, cantidad);
}   