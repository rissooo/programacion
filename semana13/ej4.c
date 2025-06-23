//Un sistema debe almacenar los puntajes de satisfacción de 20 clientes (valores enteros del 1 al 5). Validar cada ingreso. Calcular: 
//a. El promedio de satisfacción 
//b. La cantidad de clientes que calificaron con 5 
//c. Qué puntaje fue el menos frecuente
//Ayuda: Usar un segundo arreglo para contar frecuencias (conteo de votos por cada puntaje). 
#include <stdlib.h>
#include <stdio.h>

#define max 20
#define free 5
void carga (int puntaje[max]) {
    for (int i = 0; i < max; i++) {
        do {
            printf ("ingrese su puntaje de satisfaccion%d\n", + 1);
            scanf ("%d", &puntaje[i]);

            if (puntaje[i] < 1 || puntaje[i] > 5) {
            printf ("ERROR: ingrese un valor entre 1 y 5\n");
            }
        } while (puntaje[i] < 1 || puntaje[i] > 5);
    }
}

void calculos (int puntaje[max], int *promedio, int frecuencia[free], int *cantidad) {
    int suma = 0;
    int minimo = frecuencia[0];
    int menos_frecuente;

    for (int i = 0; i < max; i++) {
        *cantidad = frecuencia[4];
        suma += puntaje[i];

    for (int i = 0; i < free; i++) {
        frecuencia[i] = 0;
        if (frecuencia[i] < minimo) {
            minimo = frecuencia[i];
            menos_frecuente = i + 1;
            }
        }
    }   
    *promedio = suma/max; 
}

int main () {
    int puntaje[max], promedio, cantidad;
    int frecuencia[free];

    carga (puntaje);
    calculos (puntaje, &promedio, frecuencia, &cantidad);

    printf ("el promedio de satisfaccion es: %d\n", promedio);
    printf ("la cantidad de clientes que calificaron con 5 son:%d\n", cantidad);
    printf ("el puntaje menos fecuente fue%d\n", frecuencia);

    return 0;
}