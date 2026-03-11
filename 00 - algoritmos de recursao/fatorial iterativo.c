#include <stdio.h>

long long fatorial_iterativo(int n) {
    long long acumulador = 1;
    while (n > 1) {
        acumulador = acumulador * n;
        n = n - 1;
    }
    return acumulador;
}

int main() {
    printf("Fatorial (iterativo) de 5: %lld\n", fatorial_iterativo(5));
    return 0;
}