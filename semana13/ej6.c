#include <stdio.h>
#define max 50

void carga (float precio[max], int cantidad) {
    cantidad = 0;
    for (int i = 0; i < max; i++) {
        do {
        printf ("ingrese un precio/n");
        scanf ("%f", &precio[i]);
        } while (precio[i] != 0 && cantidad < 50);
    }
}

void validacion (float precio[max]) {
    for (int i = 0; i < max; i++) {
        if (precio[i] < 0) {
            printf ("ERROR: ingrese un numero mayor a cero/n");
        }
    }
}

void calculo (float precio[max], float mayor, float menor, int posicion_menor, float total, float promedio, int productos_menores) {
    total = 0;
    menor = 0;
    mayor = 0;
    posicion_menor = precio[0];

    for (int i = 0; i < max; i++) {
        if (precio[i] > mayor) {
            mayor = precio[i];
        }
        if (precio[i] < menor) {
            menor = precio[i];
            posicion_menor = i;
        }
        total += precio[i];
    }
    promedio = total/max;
    
    for (int i = 0; i < max; i++) {
        if (precio[i] < promedio) {
            productos_menores++;
        }
    }
}

int main () {
    float precio[max],total, mayor, menor, promedio;
    int cantidad, posicion_menor, productos_menores;

    carga (precio, cantidad);
    validcacion(precio); 
    calculo (precio, mayor, menor, posicion_menor, total, promedio, productos_menores);

    printf ("el precio mas caro es:%f/n", mayor);
    printf ("la posicion del producto mas barato es:%d/n", posicion_menor);
    printf ("el precio promedio es:%f/n", promedio);
    printf ("los productos que estan por debajo del promedio son:%d/n", productos_menores);

    return 0;
}