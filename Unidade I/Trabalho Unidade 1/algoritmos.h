#ifndef ALGORITMOS_H
#define ALGORITMOS_H

// Algoritmos de Busca
int busca_sequencial(int *vetor, int n, int chave);
int busca_binaria(int *vetor, int n, int chave);

// Algoritmos de Ordenação
void insertion_sort(int *vetor, int n);
void quick_sort(int *vetor, int inicio, int fim);

// Funções Auxiliares
void trocar(int *a, int *b);
void gerar_vetor_aleatorio(int *vetor, int n);

#endif