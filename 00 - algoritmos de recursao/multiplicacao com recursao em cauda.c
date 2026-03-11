#include <stdio.h>

// Função com recursão em cauda
int multiplicar_cauda(int x, int y, int acumulador) {
    if (y == 0) {
        return acumulador; // Caso base: retorna o total acumulado
    }
    
    // Chamada recursiva
    return multiplicar_cauda(x, y - 1, acumulador + x);
}

// função principal
int main() {
    int a = 5;
    int b = 4;
    
    int resultado = multiplicar_cauda(a, b, 0);
    
    printf("%d multiplicado por %d = %d\n", a, b, resultado);
    
    return 0;
}