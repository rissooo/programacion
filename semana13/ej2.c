#include <stdlib.h>
#include <stdio.h>

#define max 31
int cargaTemp (float temperatura[max]);
void calculoTemp (float temperatura[max], int cantidad, float *menor, int *diaMasFrio, float *promedio);

int main () {
    float temperatura[max], menor, promedio;
    int cantidad, diaMasFrio;

    cantidad = cargaTemp(temperatura);
    calculoTemp (temperatura, cantidad, &menor, &diaMasFrio, &promedio);

    printf ("la temperatura mas baja es:%2.f\n", menor);
    printf ("el dia que se vio la temperatura mas baja fue el:%d\n", diaMasFrio + 1);
    printf ("la temperatura promedio del mes es:%2.f\n", promedio);
    
    return 0;
}

int cargaTemp (float temperatura[max]) {
    int i;
    for ( i = 0; i < max; i++) {

        //if (temperatura[i] < 0) break;

        do {
            printf ("dia %d - ingresa una temperatura entre 0 y 50.0:", i + 1);
            scanf ("%f", &temperatura[i]);

            if (temperatura[i] < 0) break; 

            if (temperatura[i] < 0 || temperatura[i] > 50.0) {
                printf ("ERROR: ingresa una temperatura entre 0 y 50.0\n");
            }
        } while (temperatura[i] < 0 || temperatura[i] > 50.0);

        if (temperatura[i] < 0) break;  
        
    }
    return i;
}

void calculoTemp (float temperatura[max], int cantidad , float *menor, int *diaMasFrio, float *promedio) {
    float suma = 0;
    *menor = temperatura[0];
    *diaMasFrio = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += temperatura[i];

        if (temperatura[i] < *menor) {
            *menor = temperatura[i];
            *diaMasFrio = i;
        }

    }

    *promedio = suma / cantidad;
}
