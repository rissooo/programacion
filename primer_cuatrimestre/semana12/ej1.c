#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
float sumar (float num1, float num2, float resultado) {
    resultado = num1 + num2;
}
float restar (float num1, float num2, float resultado) {
    resultado = num1 - num2;
}
float mulplicar (float num1, float num2, float resultado) {
    resultado = num1 * num2;
}
float fividir (float num1, float num2, float resultado) {
    resultado = num1/num2;
    if (num2 == 0) {
        printf("ingrese un valor valido para dividir");
    }
}

int main (){
    int num1;
    int num2;
    int resultado;
    int opcion;

    do {
        switch (opcion) {
            case 1:
            printf ("ingrese el primer numero");
            printf ("ingrese el segundo numero");

        }

    } while (opcion != 5);
    
=======
char mensajeBienvendia (char primerainicial) {
    printf("Bienvenido %c\n", primerainicial);
    return primerainicial;
}

int main() {
    char inicial;

    printf("Ingrese la inicial de su nombre: ");
    scanf(" %c", &inicial);

    mensajeBienvendia(inicial);

    return 0;
>>>>>>> daaa8415ef86172e01719654b921b16a4315fc55
}