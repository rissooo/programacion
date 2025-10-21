// calculadora de matrices
// Versión: se agregaron comentarios explicativos por función y se corrigió la opción 3 (multiplicación).
// Se añadieron validaciones básicas de entrada (scanf) y límites respecto a MAX para evitar desbordes.

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// leer_matriz:
// Lee f x c enteros desde stdin y los almacena en m.
// Muestra el índice en formato 1-based al usuario.
// No permite leer más allá de MAX.
void leer_matriz(int f, int c, int m[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf ("elemento [%d][%d]:", i + 1, j + 1);
            scanf ("%d", &m[i][j]);    
        }
    }
}

// imprimir_matriz:
// Imprime una matriz f x c por filas, separados por tabulación.
void imprimir_matriz(int f, int c, int m[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

// sumar_matriz:
// r = a + b (elemento a elemento) para matrices f x c.
void sumar_matriz(int f, int c, int a[][MAX], int b [][MAX], int r[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}

// restar_matriz:
// r = a - b (elemento a elemento) para matrices f x c.
void restar_matriz(int f, int c, int a[][MAX], int b[][MAX], int r[][MAX]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++){
            r[i][j] = a[i][j] - b[i][j];
        }      
    }   
}

// multiplicar_matriz:
// Multiplicación clásica: A (fA x cA) * B (cA x cB) = R (fA x cB).
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

// determinante:
// Calcula determinante por expansión de cofactores (recursivo).
// Adecuado sólo para matrices pequeñas por su complejidad.
int determinante(int n, int m[][MAX]) { 
    if (n == 1) return m[0][0];
    if (n == 2)
        return m[0][0]*m[1][1] - m[0][1]*m[1][0];

    int temp[MAX][MAX];
    int sign = 1, det = 0;

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                temp[subi][subj++] = m[i][j];
            }
            subi++;
        }
        det += sign * m[0][x] * determinante(n - 1, temp);
        sign = -sign;
    }
    return det;
}

// obtener_menor:
// Construye la submatriz (menor) eliminando la fila excl_i y la columna excl_j.
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

// cofactores:
// Calcula matriz de cofactores Cof[i][j] = (-1)^(i+j) * det(menor(i,j))
void cofactores(int n, int m[][MAX], int cof[][MAX]) {
    int menor[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            obtener_menor(n, m, i, j, menor);
            cof[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinante(n - 1, menor);
        }
    }
}

// transpuesta:
// Transpone una matriz cuadrada n x n (t = m^T).
void transpuesta(int n, int m[][MAX], int t[][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = m[i][j];
        }
    }
}

// inversa:
// Calcula la inversa mediante matriz de cofactores y adjunta.
// Retorna 1 si se obtuvo inversa, 0 si determinante es 0.
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

        if (scanf ("%d", &opcion) != 1) {
            printf ("Entrada inválida.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (opcion < 1 || opcion > 9) {
            printf ("error: elija una opcion valida entre 1 y 9\n");
            continue;
        }
        
        switch (opcion) {
            case 1:
                printf("ingrese las filas y columnas de la matriz\n");
                if (scanf ("%d %d", &fA, &cA) != 2 || fA <= 0 || cA <= 0 || fA > MAX || cA > MAX) {
                    printf("Dimensiones inválidas (1..%d).\n", MAX);
                    while (getchar() != '\n');
                    break;
                }

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
                if (scanf ("%d %d", &fA, &cA) != 2 || fA <= 0 || cA <= 0 || fA > MAX || cA > MAX) {
                    printf("Dimensiones inválidas (1..%d).\n", MAX);
                    while (getchar() != '\n');
                    break;
                }

                printf ("ingrese la primer matriz\n");
                leer_matriz (fA, cA, A);

                printf ("ingrese la segunda matriz\n");
                leer_matriz (fA, cA,  B);

                restar_matriz (fA, cA, A, B, R);
                printf ("resultado de la resta\n");
                imprimir_matriz (fA, cA, R);

                break;

            case 3:
                // Corrección: eliminar lecturas duplicadas y la impresión con dimensiones incorrectas.
                printf("Ingrese cantidad de filas y columnas de la primer matriz:\n");
                if (scanf("%d %d", &fA, &cA) != 2 || fA <= 0 || cA <= 0 || fA > MAX || cA > MAX) {
                    printf("Dimensiones inválidas (1..%d).\n", MAX);
                    while (getchar() != '\n');
                    break;
                }

                printf("Ingrese cantidad de filas y columnas de la segunda matriz:\n");
                if (scanf("%d %d", &fB, &cB) != 2 || fB <= 0 || cB <= 0 || fB > MAX || cB > MAX) {
                    printf("Dimensiones inválidas (1..%d).\n", MAX);
                    while (getchar() != '\n');
                    break;
                }

                if (cA != fB) {
                    printf ("Error, las columnas de A deben ser iguales a las filas de B.\n");
                    break;
                }

                printf("Ingrese la primer matriz:\n");
                leer_matriz(fA, cA, A);

                printf("Ingrese la segunda matriz:\n");
                leer_matriz(fB, cB, B);
                
                multiplicar_matriz(fA, cA, cB, A, B, R);
                printf ("el resultado es:\n");
                imprimir_matriz(fA, cB, R);

                break;

            case 4:
                printf("Ingrese el orden de la matriz cuadrada (max %d): ", MAX);
                if (scanf("%d", &fA) != 1 || fA <= 0 || fA > MAX) {
                    printf("Error: dimension invalida.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);
                printf("El determinante es: %d\n", determinante(fA, A));
                
                break;
            
            case 5:
                printf("Ingrese el orden de la matriz (cuadrada): ");
                if (scanf("%d", &fA) != 1 || fA <= 1 || fA > MAX) {
                    printf("Error: el orden debe ser mayor que 1 y hasta %d.\n", MAX);
                    while (getchar() != '\n');
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);

                {
                    int excl_i, excl_j;
                    printf("Ingrese la fila a excluir (1 a %d): ", fA);
                    if (scanf("%d", &excl_i) != 1) { printf("Índice inválido.\n"); while (getchar() != '\n'); break; }
                    printf("Ingrese la columna a excluir (1 a %d): ", fA);
                    if (scanf("%d", &excl_j) != 1) { printf("Índice inválido.\n"); while (getchar() != '\n'); break; }

                    if (excl_i < 1 || excl_i > fA || excl_j < 1 || excl_j > fA) {
                        printf("Índices inválidos.\n");
                        break;
                    }

                    int menor[MAX][MAX];
                    obtener_menor(fA, A, excl_i - 1, excl_j - 1, menor);
                    printf("Menor de la matriz (sin fila %d y columna %d):\n", excl_i, excl_j);
                    imprimir_matriz(fA - 1, fA - 1, menor);
                }
                
                break;
            
            case 6:
                printf("Ingrese el orden de la matriz (cuadrada): ");
                if (scanf("%d", &fA) != 1 || fA <= 0 || fA > MAX) {
                    printf("Error: dimensión inválida (1..%d).\n", MAX);
                    while (getchar() != '\n');
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);

                {
                    int cof[MAX][MAX];
                    cofactores(fA, A, cof);
                    printf("Matriz de cofactores:\n");
                    imprimir_matriz(fA, fA, cof);
                }
                
                break;

            case 7:
                printf("Ingrese dimensiones de la matriz:\n");
                if (scanf("%d %d", &fA, &cA) != 2 || fA <= 0 || cA <= 0 || fA > MAX || cA > MAX) {
                    printf("Dimensiones inválidas.\n");
                    while (getchar() != '\n');
                    break;
                }
                leer_matriz(fA, cA, A);

                {
                    int t[MAX][MAX] = {0};
                    for (int i = 0; i < fA; i++) {
                        for (int j = 0; j < cA; j++) {
                            t[j][i] = A[i][j];
                        }
                    }

                    printf("Matriz transpuesta:\n");
                    imprimir_matriz(cA, fA, t);
                }
                
                break;
            
            case 8:
                printf("Ingrese orden de matriz cuadrada: ");
                if (scanf("%d", &fA) != 1 || fA <= 0 || fA > MAX) {
                    printf("Orden inválido (1..%d).\n", MAX);
                    while (getchar() != '\n');
                    break;
                }
                printf("Ingrese la matriz:\n");
                leer_matriz(fA, fA, A);
                if (inversa(fA, A, inversaM)) {
                    printf("Matriz inversa:\n");
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
