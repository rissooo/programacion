#include <stdio.h>
#include <string.h>
#define max 10
void cargaDatos (float precio[max], char nombre[max][30], int *cantidad) {
        int i = 0;
        do {
        printf ("ingrese el nombre del producto/n");
        scanf ("%c", &nombre[i]);

        do {
        printf ("ingresa el precio del producto/n");
        scanf ("%f", &precio[i]);
        if (precio[i] < 0) {
            printf ("ERROR: ingrese un precio valido/n");
        }
        } while (precio[i] <= 0);

        char seguir;
        printf ("usted desea seguir ingresando? (si/no):");
        scanf ("%c", &seguir);
        if (strcmp(seguir, "si")  != 0 && strcmp(seguir, "SI") != 0){
            break;
        }

        } while ( i < max);
        *cantidad = i; 
}

void calculos ( float precio[max], char nombre[max][30], float *mayor, float *total, float *promedio) {
    *mayor = precio[0];
    *total = 0;
    for (int i = 0; i < max; i++) {
        *total += precio[i];
        if (precio[i] > *mayor) {
            *mayor = precio[i];
        }
    }
    *promedio = *total/max;
}

int buscar(float nombres[max][30], int cantidad, char buscado[]) {
    for (int i = 0; i < max; i++) {
        if(strcmp(nombres[i], buscado) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrar(char nombres[][30], float precios[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay productos cargados.\n");
        return;
    }

    int posMayor = 0;
    printf("\n--- Lista de productos ---\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);

        if (precios[i] > precios[posMayor]) {
            posMayor = i;
        }
    }

    printf("\n El producto más caro es: %s - $%.2f\n", nombres[posMayor], precios[posMayor]);
}


int main () {
    char nombres;
    int cantidad, opcion, mayor;
    float precios;
    do {
        printf ("\n------MENU------\n");
        printf ("Elija una opcion\n");
        printf ("1: mostrar todos los productos\n");
        printf ("2: mostrar producto mas caro\n");
        printf ("3: mostrar promedio de productos\n");
        printf ("4: buscar proctos\n");
        printf ("5: salir\n");
        scanf ("%d, &opcion");

        switch (opcion) {
            case 1: mostrar(nombres, cantidad, precios);
            break;

            case 2: mostrar(nombres, cantidad, precios);
            break;

            case 3: calculos(nombres, mayor);
            break;
        }
    } while (opcion != 5);


    
}
  