#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 6
#define maxDias 5

void cargarDatos(int asistencias[max], char nombres[max][maxDias]) {
    for (int i = 0; i < max; i++) {
        printf ("Ingrese nombre del estudiante-%d\n", i + 1);
        scanf ("%49s", nombres[i]);

        for (int j = 0; j < maxDias; j++) {
            printf ("Ingrese 1 si asistio o 0 si falto a la clase\n");
            scanf ("%d", &asistencias[j]);

            if (asistencias[j] != 1 && asistencias[j] != 0) {
                printf ("ERROR: ingrese 1 si se presento o 0 si falto al la clase");
            }
        }
    }
}