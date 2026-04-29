#include <stdlib.h>
#include <stdio.h>

int main () {
    int num1;
    int num2;
    int num3;
    int resultado;

    printf ("ingrese un numero: ");
    scanf ("%d" ,&num1);
    
    printf ("ingrese otro numero: ");
    scanf ("%d",&num2);
    
    printf ("ingrese otro numero: ");
    scanf ("%d",&num3);

    resultado = num1 + num2 + num3;
    
    printf ("la suma es %d\n", resultado);
    
    getchar();
    
    return 0;
}