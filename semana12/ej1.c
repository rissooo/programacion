#include <stdio.h>
#include <stdlib.h>

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
    
}