#include <stdio.h>
#include <stdlib.h>

// definição da estrutura da celula 
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        return NULL;
    }
    novo->dado = x;
    novo->prox = NULL;

    if (f == NULL) {
        return novo;
    }

    celula *aux = f;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;

    return f;
}