#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf ("Ingrese un numero:");
    scanf ("%d", &num);

    if (num % 2 == 0) {
        printf ("Este numero es par: %d\n   ", num);
    } else {
           printf ("Este numero es impar: %d\n", num);
        }

        return 0;
}