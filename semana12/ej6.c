#include <stdio.h>

char primeraletra (char pablara[]){
    return pablara[0];
}

int main () {

char palabra2[100];
printf("ingrese una palabra\n");
fgets(palabra2, sizeof(palabra2), stdin);
char letra=primeraletra(palabra2);
printf("%c",letra);




}
