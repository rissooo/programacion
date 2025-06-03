// claculadora de matrices
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
// c son columnas, f son filas y m es la matriz
// esta funcion recorre la matriz fila por fila pide al usuario que ingrese un valor para cada posicion y almacena ese valor en m[i][j]
void leer_matriz(int f, int c, int m[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("elemento [%d][%d]:", i + 1, j + 1);
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

int determinante(int n, int m[][MAX]) { 
    //en el caso de 1x1
    if (n == 1) return m[0][0];

    //en el caso de 2x2
    if (n == 2)
        return m[0][0]*m[1][1] - m[0][1]*m[1][0];

    //temp es para guardar la submatriz que resulta de eliminar una fila y una columna
    //sign va alternando entre +1 y -1
    //det acumula el resultado
    int temp[MAX][MAX];
    int sign = 1, det = 0;

    //aca se aplica la expancion de cofactores por la primer fila
    for (int x = 0; x < n; x++) {
        // Crear submatriz quitando fila 0 y columna x
        //lo que se queda se guarda en temp
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                temp[subi][subj++] = m[i][j];
            }
            subi++;
        }

        // multiplicamos el elemento actual m[0][x] por el determinante de su submatriz en temp
        //suma al determinante y alterna los signos en forma de ajedrez
        det += sign * m[0][x] * determinante(n - 1, temp);
        sign = -sign;
    }
    //retorna el resultado
    return det;
}

void obtener_menor(int n, int m[][MAX], int excl_i, int excl_j, int menor[][MAX]) {
    int r = 0, c;
    for (int i = 0; i < n; i++) {
        if (i == excl_i) continue;
        c = 0;
        for (int j = 0; j < n; j++) {
            if (j == excl_j) continue;
            menor[r][c++] = m[i][j];
        }
        r++;
    }
}

void cofactores(int n, int m[][MAX], int cof[][MAX]) {
    int menor[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            obtener_menor(n, m, i, j, menor);
            cof[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinante(n - 1, menor);
        }
    }
}

void transpuesta(int n, int m[][MAX], int t[][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = m[i][j];
        }
    }
}

int inversa(int n, int m[][MAX], float inv[][MAX]) {
    int detA = determinante(n, m);
    if (detA == 0) {
        printf("La matriz no tiene inversa (determinante = 0).\n");
        return 0;
    }

    int cof[MAX][MAX], adj[MAX][MAX];
    cofactores(n, m, cof);
    transpuesta(n, cof, adj);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = (float)adj[i][j] / detA;
        }
    }
    return 1;

}

// doble max para que sea una matriz de 10x10
int main () {
    int opcion;
    int fA, fB, cA, cB;
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    float inversaM[MAX][MAX];
        
    do {
        printf ("\n=========calculadora de matrices=========\n");
        printf ("1: sumar matrices\n");
        printf ("2: restar matrices\n");
        printf ("3: multiplicacion de matrices\n");
        printf ("4: calcular el determinante\n");
        printf ("5: calcular el menor\n");
        printf ("6: calcular los cofactores\n");
        printf ("7: calcular la traspuesta\n");
        printf ("8: calcular la inversa\n");
        printf ("9: salir del programa\n");
        printf ("elija una opcion:\n");  

        scanf ("%d", &opcion);
        if (opcion < 1 || opcion > 9) {
            printf ("error: elija una opcion valida entre 1 y 9\n");
            continue;
        }
        
        switch (opcion) {
            case 1:
                printf("ingrese las filas y columnas de la matriz\n");
                scanf ("%d %d", &fA, &cA);

                printf ("ingrese la primer matriz\n");
                leer_matriz (fA, cA, A);

                printf ("ingrese la segunda matriz\n");
                leer_matriz (fA, cA,  B);

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
                leer_matriz (fA, cA,  B);

                restar_matriz (fA, cA, A, B, R);
                printf ("resultado de la resta\n");
                imprimir_matriz (fA, cA, R);

                break;

            case 3:
                printf("Ingrese cantidad de filas y columnas de la primer matriz:\n");
                scanf("%d %d", &fA, &cA);

                printf("Ingrese cantidad de filas y columnas de la segunda matriz:\n");
                scanf("%d %d", &fB, &cB);

                if (cA != fB) {
                    printf ("Error, las columnas de A deben ser iguales a las filas de B:\n");
                    continue;
                }

                printf("Ingrese la primer matriz:\n");
                leer_matriz  (fA, cA, A);

                printf("Ingrese la segunda matriz:\n");
<<<<<<< HEAD
                    leer_matriz(fB, cB, B);
                
                multiplicar_matriz(fA, cA, cB, A, B, R);
                imprimir_matriz(fA, cA, R);

                break;
                
                case 4:
                    printf("Usted cerro el programa:\n");

                break;

                default:
                printf("Opcion invalida, ingrese una opcion del 1 al 4:\n");
=======
                leer_matriz(fB, cB, B);
                
                multiplicar_matriz(fA, cA, cB, A, B, R);
                printf ("el resultado es:\n");
                imprimir_matriz(fA, cB, R);

                break;

            case 4:
                printf("Ingrese el orden de la matriz cuadrada (max %d): ", MAX);
                scanf("%d", &fA);
                if (fA > MAX || fA <= 0) {
                    printf("Error: dimension invalida.\n");
                    
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);
                printf("El determinante es: %d\n", determinante(fA, A));
                 
                break;
            
            case 5:
                printf("Ingrese el orden de la matriz (cuadrada): ");
                scanf("%d", &fA);
                if (fA > MAX || fA <= 1) {
                    printf("Error: el orden debe ser mayor que 1 y hasta %d.\n", MAX);
                    
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);

                int excl_i, excl_j;
                printf("Ingrese la fila a excluir (1 a %d): ", fA);
                scanf("%d", &excl_i);
                printf("Ingrese la columna a excluir (1 a %d): ", fA);
                scanf("%d", &excl_j);

                if (excl_i < 1 || excl_i > fA || excl_j < 1 || excl_j > fA) {
                    printf("Índices inválidos.\n");
                    
                    break;
                }

                int menor[MAX][MAX];
                obtener_menor(fA, A, excl_i - 1, excl_j - 1, menor);
                printf("Menor de la matriz (sin fila %d y columna %d):\n", excl_i, excl_j);
                imprimir_matriz(fA - 1, fA - 1, menor);
>>>>>>> 9cbb28630fac9c2d18c4ece573ca471eeff7e170
                
                break;
            
            case 6:
                printf("Ingrese el orden de la matriz (cuadrada): ");
                scanf("%d", &fA);
                if (fA > MAX) {
                    printf("Error: dimensión excedida.\n");
                    
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);

                int cof[MAX][MAX];
                cofactores(fA, A, cof);
                printf("Matriz de cofactores:\n");
                imprimir_matriz(fA, fA, cof);
                
                break;

            case 7:
                printf("Ingrese dimensiones de la matriz:\n");
                scanf("%d %d", &fA, &cA);
                if (fA > MAX || cA > MAX) {
                    printf("Dimensiones inválidas.\n");
                    
                    break;
                }
                leer_matriz(fA, cA, A);

                int t[MAX][MAX];
                for (int i = 0; i < fA; i++) {
                    for (int j = 0; j < cA; j++) {
                        t[j][i] = A[i][j];
                    }
                }

                printf("Matriz transpuesta:\n");
                imprimir_matriz(cA, fA, t);
                
                break;
            
            case 8:
                printf("Ingrese orden de matriz cuadrada: ");
                scanf("%d", &fA);
                leer_matriz(fA, fA, A);
                if (inversa(fA, A, inversaM)) {
                    printf(" Matriz inversa:\n");
                    for (int i = 0; i < fA; i++) {
                        for (int j = 0; j < fA; j++) {
                        printf("%.2f\t", inversaM[i][j]);
                            }
                        printf("\n");
                    }
                }

                break;
                
            case 9:
                printf("Usted cerro el programa\n");

                break;
        }

    } while (opcion != 9);

    return 0;
}
<<<<<<< HEAD

// agregar para que calcule la determinante 
// agregar para que saque la inversa
// agregar para que multiplique por un numero
// agregar para que haga la transposicion
// agregar para que haga potencia de matriz
// agregar que tenga soporte para fracciones
// IMPORTANTE: que tenga mensajes de error

=======
>>>>>>> 9cbb28630fac9c2d18c4ece573ca471eeff7e170
