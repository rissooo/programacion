#include <stdio.h>
#include <stdlib.h>
#define max 25

void cargarAlturas(float altura[max]);
void calculos(float alturas[], float *promedio, float *mayor, int *mayor170);

int main() {
    float alturas[max], promedio, mayor;
    int mayor170;

    cargarAlturas(alturas);
    calculos(alturas, &promedio, &mayor, &mayor170);

    printf ("el promedio es:%2.f\n", promedio);
    printf ("el mayor es:%2.f\n", mayor);
    printf ("la cantidad de estudiantes que miden mas de 1.70 son:%2f\n", mayor170);

    return 0;
}

void cargarAlturas (float altura[max]) {
    for (int i = 0; i < max; i++)

    do {  
        printf ("ingrese una altura %d:\n", i + 1); 
        scanf ("%f", &altura[i]);

        if (altura[i] < 1.0 || altura[i] > 2.5) {
        printf ("ERROR: ingresar una altura valida\n");
        }
    } while (altura[i] < 1 || altura[i] > 2.50);
}
void calculos (float alturas[], float *promedio, float *mayor, int *mayor170) {
    float suma = 0;
    *mayor = alturas[0];
    *mayor170 = 0;

    for (int i = 0; i < max; i++) {
        suma += alturas[i];

        if (alturas[i] > *mayor) {
            *mayor = alturas[i];
        }
        if (alturas[i] > 1.70) {
            (*mayor170)++;
        }
    }
    *promedio = suma/max;
}




