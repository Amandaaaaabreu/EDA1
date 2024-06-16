#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int desempilha(celula *p, int *y) {
    if (p->prox == NULL) {
        return 0; // Pilha vazia, não é possível desempilhar
    }
    
    celula *temp = p->prox; // Aponta para o primeiro elemento da pilha
    *y = temp->dado; // Salva o valor do elemento a ser desempilhado em y
    p->prox = temp->prox; // Atualiza o ponteiro do nó cabeça para o próximo elemento
    
    free(temp); // Libera a memória do elemento desempilhado
    
    return 1; // Desempilhamento bem sucedido
}