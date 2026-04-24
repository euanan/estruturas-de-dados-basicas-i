#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"

#define REPETICOES 30

void quick_sort_adaptador(int *v, int n) { quick_sort(v, 0, n - 1); }

void testar_ordenacao(const char* nome, void (*func)(int*, int), int n, FILE *csv) {
    double tempo_total = 0;
    for (int i = 0; i < REPETICOES; i++) {
        int *vetor = (int*) malloc(n * sizeof(int));
        gerar_vetor_aleatorio(vetor, n);
        clock_t t = clock();
        func(vetor, n);
        t = clock() - t;
        tempo_total += ((double)t) / CLOCKS_PER_SEC;
        free(vetor);
    }
    double media = tempo_total / REPETICOES;
    fprintf(csv, "%s,%d,%f\n", nome, n, media);
    printf("[%s] N=%d concluído\n", nome, n);
}

void testar_busca(const char* nome, int (*func)(int*, int, int), int n, int ord, FILE *csv) {
    double tempo_total = 0;
    int *vetor = (int*) malloc(n * sizeof(int));
    gerar_vetor_aleatorio(vetor, n);
    if (ord) quick_sort(vetor, 0, n - 1);

    for (int i = 0; i < REPETICOES; i++) {
        int chave = vetor[rand() % n];
        clock_t t = clock();
        func(vetor, n, chave);
        t = clock() - t;
        tempo_total += ((double)t) / CLOCKS_PER_SEC;
    }
    fprintf(csv, "%s,%d,%e\n", nome, n, tempo_total / REPETICOES);
    printf("[%s] N=%d concluído\n", nome, n);
    free(vetor);
}

int main() {
    srand(time(NULL));
    FILE *csv = fopen("dados.csv", "w");
    fprintf(csv, "Algoritmo,N,Tempo\n");

    int tamanhos[] = {1000, 5000, 10000, 20000, 50000};
    for (int i = 0; i < 5; i++) {
        int n = tamanhos[i];
        testar_ordenacao("InsertionSort", insertion_sort, n, csv);
        testar_ordenacao("QuickSort", quick_sort_adaptador, n, csv);
        testar_busca("BuscaSequencial", busca_sequencial, n, 0, csv);
        testar_busca("BuscaBinaria", busca_binaria, n, 1, csv);
    }
    fclose(csv);
    return 0;
}