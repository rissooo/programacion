#include <stdio.h>
#include <stdlib.h>

int main() {
    char empleados;
    int puntaje, contE, contB, contR, contD, cont_emp;
    float salario;
    
    cont_emp = 1;
    while (cont_emp <= 3); {
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
                contE++;
            } else if (puntaje >= 7 && puntaje <= 8) {
                printf ("Tu desempeño es BUENO, tu bonificacion es del 10%\n");
                salario = salario * 1.10;
                contB++;
            } else if (puntaje >= 5 && puntaje <= 6) {
                printf ("Tu desempeño es REGULAR, tu bonificacion es del 5%\n");
                salario = salario * 0.50;
                contR++;
            } else (puntaje < 5); {
                printf ("Tu desempeño es DEFICIENTE, no tienes bonificacion\n");
                contD++;
            }
            
        }
<<<<<<< HEAD
      cont_emp++;  
=======
        empleados++;
>>>>>>> 1dd0db738820c196eb0c92c1a75c6039fb2dddea
    }
    printf ("la cantidad de empleados con desempeño exelente es: %d\n", contE);
    printf ("la cantidad de empleados con desempeño bueno es: %d\n", contB);
    printf ("la cantidad de empleados con desempeño regular es: %d\n", contR);
    printf ("la cantidad de empleados con desempeño deficiente es: %d\n", contD);
    return 0;
}
