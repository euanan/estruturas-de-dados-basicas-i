#include <stdio.h>

int multiplicar_iterativo(int x, int y) {
    int acumulador = 0;
    while (y > 0) {
        acumulador = acumulador + x;
        y = y - 1;
    }
    return acumulador;
}

int main() {
    printf("Multiplicar 5 * 4 = %d\n", multiplicar_iterativo(5, 4));
    return 0;
}