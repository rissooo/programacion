#include <stdio.h>
#include <stdlib.h>

void main () {
    float monto,retiro;

    printf("ingrese el saldo de la cuenta\n");
    scanf("%f",&monto);

    printf("ingrese cuanto quiere retirar\n");
    scanf("%f",&retiro);

    if (retiro>monto){
    printf("el retiro no es posible\n");

    }else{ 
    monto=monto-retiro;
    printf("el saldo restante es %f\n",monto);
    
}