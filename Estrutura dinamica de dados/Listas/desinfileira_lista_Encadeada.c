#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desenfileira(celula *f, int *y) {
    if (f->prox == NULL) {
        // Fila vazia, não é possível desenfileirar
        return 0;
    }
    
    celula *temp = f->prox; // Guarda o endereço do primeiro elemento da fila
    *y = temp->dado; // Salva o valor do primeiro elemento em y
    f->prox = temp->prox; // Atualiza o ponteiro do início da fila para o próximo elemento
    
    free(temp); // Libera a memória do primeiro elemento
    
    return 1; // Remoção bem sucedida
}