#include <stdio.h>
#include <stdlib.h>
#define estudiantes 6
#define dias 5
#define nombre 30

void carga (char Estudiantes[estudiantes][nombre], int Dias[estudiantes][dias]) {
    for (int i = 0; i < estudiantes; i++) {   
        printf ("ingrese nombre del estudiante", i + 1);
        scanf ("%s", Estudiantes[i]);
        for (int j = 0; j < dias; j++) {
            printf("asistio a la clase del dia %d? 1=si, 2=no", j + 1);
            scanf ("%d", &Dias[i][j]);
        }
    }
}

void total (char Estudiantes[estudiantes][nombre], int Dias[estudiantes][dias], int *total) {
    for (int i = 0; i < estudiantes; i++) {
        for (int j = 0; j < dias; j++) {
            *total += Dias[i][j];
        }
    }
}

void mas_asistencias (char Estudiantes[estudiantes][nombre], int Dias[estudiantes][dias], int *mayor) {
    *mayor = 0;
    for (int j = 0; j < dias; j++) {
        *mayor += Dias[0][j];
    }
}

void asistenciasXdia (char Estudiantes[estudiantes][nombre], int Dias[estudiantes][dias]) {
    for (int i = 0; i < estudiantes; i++) {
        for (int j = 0; j < dias; j++) {
            printf("%d ", Dias[i][j]);
        }
    }
}

switch (opcion) {
    printf ("----menu----"):
    printf ("elija una opcion:");
    printf ("")
}