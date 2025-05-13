#include <stdio.h>
#include <stdlib.h>

int main() {
    float valor;
    float descuento;
    float total;
    
    printf ("Ingrese el valor de venta:");
    scanf ("%f", &valor);

    if (valor < 0) {
        printf ("Ingrese un valor valido mayor que 0\n");
    } else if (valor >= 100000) {
        descuento = valor * 15;
        total = valor - descuento;
        printf ("Su descuento del 15%%: %.2f\n", descuento);
        printf ("su total con descuento es: %.2f\n", total);
    } else (valor < 100000 &&  valor != 0); {
        descuento = valor * 10;
        total = valor - descuento;
        printf ("Su descuento es del 10%%: %.2f\n", descuento);
        printf ("Su total con descuento es: %.2f\n", total);
    }

    return 0;
}