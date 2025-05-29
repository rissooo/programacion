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
// doble max para que sea una matriz de 10x10
int main () {
    int opcion;
    int fA, fB, cA, cB;
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
        
    do {
        printf ("\n=========calculadora de matrices=========\n");
        printf ("1: sumar matrices\n");
        printf ("2: restar mtrices\n");
        printf ("3: multiplicacion de matrices\n");
        printf ("4: calcular el determinante");
        printf ("5: salir\n");
        printf ("elija una opcion\n");  
        scanf ("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("ingrese las filas y columnas de la matriz\n");
                scanf ("%d %d", &fA, &cA    );

                printf ("ingrese la primer matriz\n");
                leer_matriz (fA, cA, A);

                printf ("ingrese la segunda matriz\n");
                leer_matriz (fB, cB,  B);

                sumar_matriz (fA, cA, A, B, R);
                printf ("el resultado de la suma es:\n");
                imprimir_matriz (fA, cA, R);
            
                break;

            case 2:
                printf ("ingrese las filas y columnas de la matriz\n");
                scanf ("%d %d", &fA, &cA);

                printf ("ingrese la primer matriz\n");
                leer_matriz (fA, cA, A);

                printf ("ingrese la segunda matriz\n");
                leer_matriz (fB, cB,  B);

                restar_matriz (fA, cA, A, B, R);
                printf ("resultado de la resta\n");
                imprimir_matriz (fA, cA, R);

                break;

            case 3:
                printf("Ingrese cantidad de filas y columnas de la primer matriz:\n");
                scanf("%d %d", &fA, &cA);
                leer_matriz (fA, cA, A);

                printf("Ingrese cantidad de filas y columnas de la segunda matriz:\n");
                scanf("%d %d", &fB, &cB);

                if (cA != fB) {
                    printf ("Error, las columnas de A deben ser iguales a las filas de B:\n");
                }

                printf("Ingrese la primer matriz:\n");
                    leer_matriz(fA, cA, A);

                printf("Ingrese la segunda matriz:\n");
                    leer_matriz(fB, cB, B);
                
                leer_matriz(fB, cB, B);
                multiplicar_matriz(fA, cA, cB, A, B, R);
                imprimir_matriz(fA, cA, R);

                break;
                
                case 4:

                case 5:
                printf("Usted cerro el programa:\n");

                break;

                default:
                printf("Opcion invalida, ingrese una opcion del 1 al 5:\n");
                
                break;
        }

    } while (opcion != 4);

    return 0;
}

// agregar para que calcule la determinante
// agregar para que saque la inversa
// agregar para que saque el rango
// agregar para que multiplique por un numero
<<<<<<< HEAD
=======
// rafa la concha de tu madre
// rafa la concha de tu madre x2
>>>>>>> a589bcc255b27eeb449375b4dfe7444120064b0e
// agregar para que haga la transposicion
// que tenga soporte para fracciones 
// IMPORTANTE: que tenga mensajes de error


