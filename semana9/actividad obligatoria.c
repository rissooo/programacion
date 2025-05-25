#include <stdio.h>
#include <stdlib.h>

int main() {
    char empleados[50];
    int puntaje, contE = 0, contB = 0, contR = 0, contD = 0, cont_emp = 1;
    float salario;
    
    while (cont_emp <= 3) {
        printf ("Ingresa nombre del empleado\n");
        scanf ("%s", empleados);
        
        printf ("Ingrese salario base del empleado ingresado anteriormente\n");
        scanf ("%f", &salario);

        do {
            printf ("Ingrese puntaje del empleado ingresado anteriormente\n");
            scanf ("%d", &puntaje);

            if (puntaje < 0 || puntaje > 10) {
                printf ("Ingrese un puntaje valido");
            }
        
        } while (puntaje < 0 || puntaje > 10);
            
             if (puntaje >= 9 && puntaje <= 10) {      
                printf ("Tu desempeno es EXELENTE, tu bonificacion es del 20%%\n");
                salario = salario * 1.20;
                contE++;
            } else if (puntaje >= 7 && puntaje <= 8) {
                printf ("Tu desempeno es BUENO, tu bonificacion es del 10%%\n");
                salario = salario * 1.10;
                contB++;        
            } else if (puntaje >= 5 && puntaje <= 6) {
                printf ("Tu desempeno es REGULAR, tu bonificacion es del 5%%\n");
                salario = salario * 1.05;
                contR++;
            } else {
                printf ("Tu desempeno es DEFICIENTE, no tienes bonificacion\n");
                contD++;
            }
      cont_emp++; 
    }
    printf ("la cantidad de empleados con desempeno exelente es: %d\n", contE);
    printf ("la cantidad de empleados con desempeno bueno es: %d\n", contB);
    printf ("la cantidad de empleados con desempeno regular es: %d\n", contR);
    printf ("la cantidad de empleados con desempeno deficiente es: %d\n", contD);
    return 0;
}
