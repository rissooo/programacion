#include <stdio.h>
#include <stdlib.h>

float suma(float num1, float num2) {
    return num1 + num2;
}

float resta(float num1, float num2) {
    return num1 - num2;
}

float multiplicar(float num1, float num2) {
    return num1 * num2;
}

float dividir(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division por cero no permitida.\n");
        return 0;
    }
}

int main () {
    float num1, num2;
    int opcion;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);

    printf("Seleccione una operacion:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Resultado: %.2f\n", suma(num1, num2));
            break;
        case 2:
            printf("Resultado: %.2f\n", resta(num1, num2));
            break;
        case 3:
            printf("Resultado: %.2f\n", multiplicar(num1, num2));
            break;
        case 4:
            printf("Resultado: %.2f\n", dividir(num1, num2));
            break;
        default:
            printf("Opcion no valida.\n");
            break;
    }

    return 0;
    
}