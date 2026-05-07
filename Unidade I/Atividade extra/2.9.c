#include <stdio.h>

// Versão (a) - O(n^2)
double polinomio_simples(int n, double a[], double x) {
    double resultado = 0.0;
    for (int i = 0; i < n; i++) {
        double potencia_x = 1.0;
        // Calcula x^i manualmente dentro do loop
        for (int j = 0; j < i; j++) {
            potencia_x *= x;
        }
        resultado += a[i] * potencia_x;
    }
    return resultado;
}

// Versão (b) - O(n) usando a Regra de Horner
double polinomio_horner(int n, double a[], double x) {
    double resultado = a[n-1];
    // Percorre os coeficientes de trás para a frente
    for (int i = n - 2; i >= 0; i--) {
        resultado = resultado * x + a[i];
    }
    return resultado;
}

int main() {
    // Exemplo: P(x) = 3 + 2x + 5x^2 -> coeficientes: {3, 2, 5}, n = 3, x = 2
    double coefs[] = {3.0, 2.0, 5.0};
    double x = 2.0;
    
    printf("Resultado O(n^2): %.2f\n", polinomio_simples(3, coefs, x));
    printf("Resultado O(n): %.2f\n", polinomio_horner(3, coefs, x));
    
    return 0;
}