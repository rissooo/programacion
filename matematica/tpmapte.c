// claculadora de matrices
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
// c son columnas, f son filas y m es la matriz
// esta funcion recorre la matriz fila por fila pide al usuario que ingrese un valor para cada posicion y almacena ese valor en m[i][j]
void leer_matriz(int f, int c, int m[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("elemento [%d][%d]\n:", i + 1, j + 1);
            scanf ("%d", &m[i][j]);    
        }
    }
}
// imprime cada valor de la matriz y tamb imprime por filas
void imprimir_matriz(int f, int c, int m[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
// a es la primer matriz, b es la segunda matriz y r es el resultado
// suma la matriz
void sumar_matriz(int f, int c, int a[][MAX], int b [][MAX], int r[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }  
    }
}
// resta la matriz
void restar_matriz(int f, int c, int a[][MAX], int b[][MAX], int r[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++){
            r[i][j] = a[i][j] - b[i][j];
        }      
    }   
}
// multiplica la matriz
void multiplicar_matriz( int fA, int cA, int cB, int a[][MAX], int b[][MAX], int r[][MAX]) {
    for (int i = 0; i < fA; i++) {
        for (int j = 0; j < cB; j++) {
            r[i][j] = 0;
                for (int k = 0; k < cA; k++) {
                    r[i][j] += a[i][k] * b[k][j];   
            }       
        }
    }
}

int main () {
printf ("\n=========calculadora de matrices=========\n");
printf ("1: sumar matrices\n");
printf ("2: restar mtrices\n");
printf ("3: multiplicacion de matrices\n");
printf ("4: salir\n");
printf ("elija una opcion\n");

}


