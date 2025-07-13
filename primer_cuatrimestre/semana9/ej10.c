#include <stdio.h>
#include <stdlib.h>

void main() {
    float num;
    float num2;
    int eleccion;
    float rosaultado;

    printf ("ingrese un numero\n");
    scanf ("%f", &num);  

     printf ("ingrese un segundo numero\n");
     scanf ("%f", &num2);
    
     do {
     printf ("ingrese: 1 para informar suma, 2 para informar resta, 3 para informar multiplicacion, 4 para informar divicion y 5 para salir del programa\n");
     scanf  ("%d", &eleccion);

     if (eleccion < 1 && eleccion > 5) {
        printf ("Ingrese un valor valido");
     }
    } while (eleccion != 5);
