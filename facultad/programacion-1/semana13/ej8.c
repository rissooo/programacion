#include <stdio.h>
#include <stdlib.h>

#define est 6
#define dias 5

void carga (char nombres[est][30], int asistencias[est][dias]) {
    for (int i = 0; i < est; i++) {
        printf("ingresa el nombre del alumno\n");
        scanf("%s", nombres[i]);
        
        for(int j = 0; j < dias; j++) {
            do {
            printf("ingresa 1 si asistio a la clase o 0 si falto el alumno\n", i + 1);
            scanf("%d", &asistencias[i][j]);

            if (asistencias[i][j] != 1 && asistencias[i][j] != 0) {
                printf("ERROR: ingresa un valor correcto\n");
                }
            } while (asistencias[i][j] != 0 && asistencias[i][j] != 1);
        }
    }
}

void asistenciasXdia (char nombres[est][30], int asistencias[est][dias]) {
    for (int j = 0; j < dias; j++) {
        int contador = 0;

        for (int i = 0; i < est; i++) {
            if(asistencias[i][j] == 1) {
                contador++;
            }
        }

        printf("Dia %d: asistieron %d alumnos%d\n", j + 1, contador);
    }
}

void total (char nombres[est][30], int asistencias[est][dias]) {
    for (int i = 0; i < est; i++) {
        int total = 0;
        for(int j = 0; j < dias; j++) {
            total += asistencias[i][j];
        }
        printf("Alumno %s: Total asistencias = %d\n", nombres[i], total);
    }
}

void mayor (char nombres[est][30], int asistencias[est][dias]) {

    int mayor = 0;
    int alumno_mayor = 0;

    for (int i = 0; i < est; i++) {
        int suma = 0;

        for(int j = 0; j < dias; j++) {
            suma += asistencias[i][j];
        }

        if (suma > mayor) {
            mayor = suma;
            alumno_mayor = i;
        }
    }

    printf("El alumno con mas asistencias es %s con %d asistencias\n", nombres[alumno_mayor], mayor);
}


void menu (char nombres[est][30], int asistencias[est][dias]) {
    int opcion;

    do {
            printf("ingrese:\n");
            printf("1 si quiere ver el total de asistencias por estudiante\n");
            printf("2 si quiere ver qué estudiante asistió más veces\n");
            printf("3 si quiere ver asistencia por día (cuántos estudiantes asistieron cada día)\n");
            printf("4 para salir");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1: 
                total(nombres, asistencias);
                break;

                case 2:
                mayor(nombres, asistencias);
                break;

                case 3:
                asistenciasXdia(nombres, asistencias);
                break;

                case 4:
                break;
            }
    } while (opcion != 4);
}

int main () {
    char nombres[est][30];
    int asistencias[est][dias];

    carga(nombres, asistencias);
    menu(nombres, asistencias);

    return 0;
}