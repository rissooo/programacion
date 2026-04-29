#include <stdio.h>
#include <stdlib.h>

#define operarios 10
#define dias 3

void carga (char nombres[operarios][30], int produccion[operarios][dias]) {
    for (int i = 0; i < operarios; i++) {
        printf("ingresa el nombre del operario\n", i + 1);
        scanf("%s", nombres[i]);
        for (int j = 0; j < dias; j++) {
            printf("ingresa la produccion del operario:\n", i + 1);
            scanf("%d", &produccion[i][j]);

            if (produccion[i][j] < 0) {
                printf("ERROR: ingresa un valor mayor a 0\n");
            }
        }
    }
}

void calculos (char nombres[operarios][30], int produccion[operarios][dias]) {
    for (int i = 0; i < operarios; i++) {
        int total = 0;
        for (int j = 0; j < dias; j++) {
            total += produccion[i][j];
            printf ("total: %f\n", total);
        }
        int promedio = total/dias;
    }
}

int busqueda (char nombres[operarios][30], int produccion[operarios][dias]) {
    int mayor = -1;
    int indice = -1;
    for (int i = 0; i < operarios; i++) {
        int total = 0;
        for (int j = 0; j < dias; j++) {
            total += produccion[i][j]; 
        }
        if (total > mayor) {
            mayor = total;
            indice = i;
        }
    }
    if (indice != -1) {
        printf ("El operario con mayor produccion es %s con un total de %d\n", nombres[indice], mayor);
    }
}

int main() {
    char nombres[operarios][30];
    int produccion[operarios][dias];

    carga (nombres, produccion);

    total
}