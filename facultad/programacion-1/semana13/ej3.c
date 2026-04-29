#include <stdio.h>
#include <stdlib.h>

#define max 15
void carga (float ventas[max]) {
    for (int i = 0; i < max; i++) {
        do {
            printf ("ingrese un valor de venta%d\n", + 1);
            scanf ("%f", &ventas[i]);

            if (ventas[i] < 0) {
                printf ("ERROR: ingrese un valor superior a 0\n");
            }
        } while (ventas[i] < 0);
        
    }
    
}

void calculo (float ventas[max], float *total, int mayorventa, float *promedio, float *dias_por_encima_del_promedio) {
    float suma;
    float dias = ventas[0];
    mayorventa = 0;
    *dias_por_encima_del_promedio = 0;
    suma = 0;
    *total = 0;
    for (int i = 0; i < max; i++) {
        *promedio = *total/max;
        *total += ventas[i];

        if (ventas[i] > *promedio) {
            (*dias_por_encima_del_promedio)++;
        }

        if (ventas[i] > max) {
            dias = ventas[i];
            mayorventa =i;
        }

    }   
    
}

int main () {
    float ventas[max], mayorventa, promedio, dias_por_encima_del_promedio, total;
    
    carga (ventas);
    calculo (ventas, &total, mayorventa, &promedio, &dias_por_encima_del_promedio);
    
    printf ("el total vendido es:%2.f\n", total);
    printf ("el dia con mayor venta es:%d\n", mayorventa);
    printf ("el promedio diario es de ventas es:%2.f\n", promedio);
    printf ("los dias que pasaron el promedio son:%d\n", dias_por_encima_del_promedio);

    return 0;
}