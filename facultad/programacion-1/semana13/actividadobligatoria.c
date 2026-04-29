#include <stdio.h>

#define MAX_CALIFICACIONES 100

int main() {
    float calificaciones[MAX_CALIFICACIONES];
    int cantidad = 0;
    int opcion;
    float calificacion;

    do {
        printf("1: Ingresar calificacion de un estudiante\n");
        printf("2: Mostrar promedio de calificaciones\n");
        printf("3: Mostrar calificacion mas alta\n");
        printf("4: Mostrar calificacion mas baja\n");
        printf("5: Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 1 || opcion > 5) {
            printf("Opcion invalida intente nuevamente.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                do {
                    printf("Ingrese calificacion (0 a 10): ");
                    scanf("%f", &calificacion);
                    if (calificacion < 0 || calificacion > 10) {
                        printf("Calificacion invalida debe estar entre 0 y 10.\n");
                    }
                } while (calificacion < 0 || calificacion > 10);
                if (cantidad < MAX_CALIFICACIONES) {
                    calificaciones[cantidad] = calificacion;
                    cantidad++;
                    printf("Calificacion guardada correctamente.\n");
                } else {
                    printf("No se pueden ingresar mas calificaciones.\n");
                }
                break;
            case 2:
                if (cantidad == 0) {
                    printf("No hay calificaciones ingresadas.\n");
                } else {
                    float suma = 0;
                    for (int i = 0; i < cantidad; i++) {
                        suma += calificaciones[i];
                    }
                    printf("Promedio de calificaciones: %.2f\n", suma / cantidad);
                }
                break;
            case 3:
                if (cantidad == 0) {
                    printf("No hay calificaciones ingresadas.\n");
                } else {
                    float max = calificaciones[0];
                    for (int i = 1; i < cantidad; i++) {
                        if (calificaciones[i] > max) {
                            max = calificaciones[i];
                        }
                    }
                    printf("Calificacion mas alta: %.2f\n", max);
                }
                break;
            case 4:
                if (cantidad == 0) {
                    printf("No hay calificaciones ingresadas.\n");
                } else {
                    float min = calificaciones[0];
                    for (int i = 1; i < cantidad; i++) {
                        if (calificaciones[i] < min) {
                            min = calificaciones[i];
                        }
                    }
                    printf("Calificacion mas baja: %.2f\n", min);
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
        }

    } while (opcion != 5);
    return 0;
}