#include <stdio.h>

int main (){
    int array[5] = {1, 2, 3, 4, 5};
    int suma = 0;
    float promedio;

    for (int i = 0; i < 5; i++)
    {
        printf ("La suma de los numeros ingresados son: %d\n", 1 + i);
        scanf ("%d\n", array[i]);
        suma += array[i];

        promedio = suma / 5;
        printf ("la suma es: %d/n", suma);
        printf ("el promedio  es: %d/n", promedio);
    }
    
    return 0;
}