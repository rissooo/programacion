//Se deben registrar los puntajes obtenidos (números enteros entre 0 y 100) por hasta 40 alumnos en un examen. 
//La carga finaliza si se ingresa un número fuera de rango o se completan los 40 alumnos. 
//Calcular: 
//a. El puntaje más alto 
//b. Cuántos estudiantes aprobaron (puntaje >= 60) 
//c. El promedio general d. El porcentaje de desaprobados 
//● Usar una función para la carga y validación. 
//● Otra para los cálculos. 

#include <stdio.h>
#include <stdlib.h>
#define max 40

void carga (int puntaje [max]) {
    for (int i = 0; i < max; i++) {
        do {
            printf ("ingrese un puntaje entre 0 y 100%d\n", + 1);
            scanf ("%d", &puntaje[i]);

            if (puntaje[max] < 0 || puntaje[max] > 100) {
                printf ("ERROR ingrese un valor dentro del rango mencionado anteriormente\n");
            }
            
        } while (puntaje[max] > 0 || puntaje[max] < 100);
    }
}

void calculo () {}