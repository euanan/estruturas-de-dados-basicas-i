#include "algoritmos.h"
#include <stdlib.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gerar_vetor_aleatorio(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % (n * 10);
    }
}

int busca_sequencial(int *vetor, int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == chave) return i;
    }
    return -1;
}

int busca_binaria(int *vetor, int n, int chave) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (vetor[meio] == chave) return meio;
        if (vetor[meio] < chave) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

void insertion_sort(int *vetor, int n) {
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

void quick_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = vetor[fim];
        int i = (inicio - 1);
        for (int j = inicio; j < fim; j++) {
            if (vetor[j] <= pivo) {
                i++;
                trocar(&vetor[i], &vetor[j]);
            }
        }
        trocar(&vetor[i + 1], &vetor[fim]);
        int p = i + 1;
        quick_sort(vetor, inicio, p - 1);
        quick_sort(vetor, p + 1, fim);
    }
}