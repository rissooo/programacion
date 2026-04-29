#include <stdio.h>
#include <stdlib.h>

#define vendedores 5
#define meses 6

void carga(char nombres[vendedores][30], int ventas[vendedores][meses]) {
    for (int i = 0; i < vendedores; i++) {
        printf("ingresa el nombre del vendedor\n");
        scanf("%s", nombres[i]);
        
        for (int j = 0; j < meses; j++) {
            printf("ingresa el monto de venta del vendedor\n");
            scanf("%d", &ventas[i][j]);

            if (ventas[i][j] < 0) {
                printf ("ERROR: ingresa un valor mayor a 0\n");
            }
        }
    }
}

void total(char nombres[vendedores][30], int ventas[vendedores][meses]) {
    for (int i = 0; i < vendedores; i++) {
        int total = 0;
        for (int j = 0; j < meses; j++) {
            total += ventas[i][j];
        }
        printf("mostrar total: \n", total)
    }
}

void febrero(char nombres[vendedores][30], int ventas[vendedores][meses]) {
    for (int i = 0; i < vendedores; i++) {
        printf("ventas de febrero:\n");
        for (int j = 0; j < meses; j++) {
            printf("%s: %d\n", nombres[i], ventas[i][1]);
        }
    }
}

