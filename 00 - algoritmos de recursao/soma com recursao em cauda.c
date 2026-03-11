#include <stdio.h>

// Função auxiliar
int soma_recursiva_cauda(int n, int acumulador) {
    if (n == 0) {
        return acumulador; // Caso base: retorna o total acumulado
    }
    return soma_recursiva_cauda(n - 1, acumulador + n);
}

// Função principal
int soma(int n) {
    return soma_recursiva_cauda(n, 0);
}

int main() {
    int numero = 5;
    printf("Soma de 1 até %d = %d\n", numero, soma(numero));
    return 0;
}