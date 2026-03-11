#include <stdio.h>

int soma_iterativa(int n) {
    int acumulador = 0; // Valor inicial que era passado na recursão
    while (n > 0) {
        acumulador = acumulador + n;
        n = n - 1;                   
    }
    return acumulador;
}

int main() {
    printf("Soma de 5 = %d\n", soma_iterativa(5));
    return 0;
}