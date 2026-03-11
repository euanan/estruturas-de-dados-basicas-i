#include <stdio.h>

long long fatorial_cauda(int n, long long acumulador) {
    if (n <= 1) {
        return acumulador; // Caso base: retorna o produto acumulado
    }
    
    return fatorial_cauda(n - 1, acumulador * n);
}

//Função principal
int main() {
    int numero = 5;
    
    long long resultado = fatorial_cauda(numero, 1);
    
    printf("O fatorial de %d e: %lld\n", numero, resultado);
    
    return 0;
}