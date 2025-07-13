#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1;
    int num2;

    printf ("ingresa un numero:");
    scanf ("%d", &num1);

    printf ("ingrese el segundo numero:");
    scanf ("%d", &num2);

    if (num1 > num2) {
        printf ("El mayor es %i\n", num1);
    } else {
        printf ("El mayor es %i\n", num2);
    }

    return 0;
}