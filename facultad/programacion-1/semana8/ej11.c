#include <stdio.h>
#include <stdlib.h>

int main() {
    int num3;
    float num;
    float num2;
    float resultado;
    
    printf ("ingrese un numero\n");
    scanf ("%f", &num);

    printf ("ingrese el segundo numero\n");
    scanf ("%f", &num2);
    
    do {
        
        printf ("ingrese 1 para sumar, 2 para restar, 3 para dividir, 4 para multiplicar o 5 para finalizar\n");
        scanf ("%d", &num3);
    
        switch (num3) {
            case 1:  
                resultado = num + num2; 
                printf ("Resultado es: %.2f\n", resultado);
                break;
            case 2:
                resultado = num - num2; 
                printf ("El resultado es: %.2f\n", resultado);
                break;
            case 3: 
                resultado = num / num2; 
                printf ("El resultado es: %.2f\n", resultado);
                break;
            case 4: 
                resultado = num * num2;
                printf ("El resultado es: %.2f\n", resultado); 
                break;
            case 5:
                printf("Programa finalizado\n");
                break;
            default: 
                printf ("Numero invalio");
                break;
        }

    }while (num3 !=5);
    
    return 0;

}