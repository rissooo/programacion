#include <stdio.h>
#include <stdlib.h>

int esPrimos (num) {
    if (num < 2) {
        return 0; // No es primo
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // No es primo
        }
    }
    return 1; // Es primo
} 