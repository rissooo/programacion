#include <stdio.h>
#include <stdlib.h>

void main ()  {
char vendedores=65;
int ventas=0;
int acum=0;
float comision;
    
    while (vendedores<70){
        printf("Vendedor letra %c\n",vendedores);
        printf("ingrese el precio de venta\n");
        scanf("%i",&ventas);
    while (ventas>0){
        printf("ingrese el valor de venta, si no desea continuar agrese un 0\n");
        scanf("%i",&ventas);
        acum+=ventas;
    }

        comision=acum*0.025;
        printf("la comision del vendedor %c es %.2f\n",vendedores,comision);
        printf("siguiente vendedor\n");

        acum=0;
        comision=0;
        vendedores++;
    }