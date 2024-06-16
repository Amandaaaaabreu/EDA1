#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // vetor que representa a fila
    int N; // tamanho da fila
    int inicio, fim; // indicadores de inicio e fim da fila
} fila;

int enfileira(fila *f, int x) {
    if ((f->fim + 1) % f->N == f->inicio) {
        return 0; // fila cheia
    }
    
    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    
    return 1; // enfileiramento bem sucedido
}

int desenfileira(fila *f, int *y) {
    if (f->inicio == f->fim) {
        return 0; // fila vazia
    }
    
    *y = f->v[f->inicio]; // armazenar o valor do elemento que será removido da fila no endereço de memória apontado por y 
    f->inicio = (f->inicio + 1) % f->N; // atualizando o cod para apontar pro proximo elemento da fila 
    
    return 1; // desenfileiramento bem sucedido
}
