#include <stdio.h>
#include <stdlib.h>

int espar (int num) {
    return (num == 0 || (num % 2 == 0));
}

int main() {
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (espar(num)) {
        printf("El numero %d es par.\n", num);
    } else {
        printf("El numero %d es impar.\n", num);
    }

    return 0;
}