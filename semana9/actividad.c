#include <stdio.h>
#include <stdlib.h>

int main() {
    int empleados;
    int puntaje;
    float salario;
    
    while (empleados > 3); {
        printf ("Ingresa nombre del empleados\n");
        scanf ("%d", &empleados);
        
        while (salario > 0) {

            printf ("Ingrese salario base del empleados ingresado anteriormente\n");
            scanf ("%f", &salario);

        }
        
        while (puntaje > 0 && puntaje < 10) {
        
            printf ("Ingrese puntaje del empleado ingresado anteriormente\n");
            scanf ("%d", &puntaje);

            if (puntaje < 0 || puntaje > 10) {
                printf ("Ingrese un puntaje valido");
            } else if (puntaje >= 9 && puntaje <= 10) {
                printf ("Tu desempeño es EXELENTE, tu bonificacion es del 20%");
                salario = salario * 1.20;
            } else if (puntaje >= 7 && puntaje <= 8) {
                printf ("Tu desempeño es BUENO, tu bonificacion es del 10%\n");
                salario = salario * 1.10;
            } else if (puntaje >= 5 && puntaje <= 6) {
                printf ("Tu desempeño es REGULAR, tu bonificacion es del 5%\n");
                salario = salario * 0.50;
            } else (puntaje < 5); {
                printf ("Tu desempeño es DEFICIENTE, no tienes bonificacion\n");
            }

        }
    }

    return 0;
}
