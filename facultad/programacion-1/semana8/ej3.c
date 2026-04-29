#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    printf ("Ingrese un numero:");
    scanf ("%d", &num);

    if (num == 0) {
        printf ("El numero es nulo");
    } 
     else if (num < 0) {
        printf ("El numero es negativo");
     }else {
        printf ("El numero es postivo");
    }
    
    return 0;
}