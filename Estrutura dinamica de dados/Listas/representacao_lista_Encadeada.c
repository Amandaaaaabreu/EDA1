#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira(celula **f, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    novo->dado = x;
    
    if (*f == NULL) {
        *f = novo;
        novo->prox = novo;
    } else {
        novo->prox = (*f)->prox;
        (*f)->prox = novo;
        *f = novo;
    }
}

int desenfileira(celula **f, int *y) {
    if (*f == NULL) {
        return 0; // Fila vazia
    }

    celula *removido = (*f)->prox;
    *y = removido->dado;

    if ((*f)->prox == *f) {
        free(removido);
        *f = NULL; // Se houver apenas um elemento na fila
    } else {
        (*f)->prox = removido->prox;
        free(removido);
    }

    return 1; // Desenfileiramento bem-sucedido
}