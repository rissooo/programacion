#include <stdio.h>
#include <stdlib.h>
#define max 40

int carga (int puntaje[max]) {
    do {
    for (int i = 0; i < max; i++) {
        printf ("ingrese el puntaje del alumno en un rango del 0 al 100\n");
        scanf ("%d", &puntaje[i]);

        if (puntaje < 0 || puntaje > 100) {
            printf ("ERROR: ingrese un valor correcto\n");
            }
        }
    } while (puntaje < 0 || puntaje > 100);
}

void calculos (int puntaje[max], int cantidad) {
    float mayor = puntaje[0];
    float total = 0;
    int desaprobados;
    int aprobados;
    float promedio;
    
    if (cantidad == 0) {
        printf ("no se ingresaron notas\n");
    }

    for (int i = 0; i < max; i++) {
        total += puntaje[i];

        if (mayor < puntaje[i]) {
            mayor = puntaje[i];
        }

        if (puntaje[i] > 60) {
            aprobados++;
        } else {
            desaprobados++;
        }
    }
    promedio = total/max;
    
    printf ("resultados\n");
    printf ("puntaje mas alto: %d\n", mayor);
    printf ("cantidad de desaprobados: %d\n", desaprobados);
    printf ("el promedio es: %d\n", promedio);
    printf ("cantidad de aprobados :%d\n", aprobados);
}

int main () {
    int puntaje[max];
    int cantidad;

    cantidad = carga(puntaje);
    calculos(puntaje, cantidad);
}