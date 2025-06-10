//Almacenar las alturas (reales en metros) de 25 estudiantes en un arreglo. Validar que las alturas estén entre 1.0 y 2.5 metros.
//Calcular:
//a. La altura promedio
//b. La mayor altura
//c. Cuántos estudiantes miden más de 1.70
//Usar una función para cargar y validar las alturas.
//Usar otra función para los cálculos estadísticos.

#include <stdio.h>
#include <stdlib.h>

#define N 25
void cargarAlturas (float alturas[], int n) {
    for (int i = 0; i < n; i++) {
        float altura; 

        do
        {
            printf ("ingrese la altura del estudiante %d (entre1.0 y 2.5):", i + 1);
            scanf ("%f", &altura);

            if (altura < 1.0 || altura > 2.5) {
                printf ("ERROR: ingrese una altura valida\n");
            }
        } while (altura < 1.0 || altura > 2.5);
        alturas[i] = altura;
        
    }
    
}

void estadisticas (float alturas[], int n, float promedio, float mayor, int contador) {
    float suma = 0;

    mayor = alturas[0];
    contador = 0;

    for (int i = 0; i < n; i++) {
        suma += alturas[i]; 
        
        if (alturas[i] > mayor) {
            mayor = alturas[i];
        }

        if (alturas[i] > 1.70) {
            contador++;
        }

        promedio = suma; 
    }

}