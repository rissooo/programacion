#include <stdio.h>
#include <stdlib.h>

#define VENDEDORES 5
#define NOMBRES 30
#define MESES 6

void carga (char Vendedores[VENDEDORES][NOMBRES], int Meses[VENDEDORES][MESES]) {
    for (int i = 0; i < VENDEDORES; i++) {
        printf ("ingrese nombre del vendedor\n", i);
        scanf ("%s", Vendedores[i]);
        for (int j = 0; j < MESES; j++) {
            printf ("ingrese el importe vendido en el mes\n", j);
            scanf("%d", &Meses[i][j]);
            
            if (Meses < 0) {
                printf ("ingrese un valor mayor a 0\n");
            }
        }
    }
}


void total (char Vendedores[VENDEDORES][NOMBRES], int Meses[VENDEDORES][MESES])
