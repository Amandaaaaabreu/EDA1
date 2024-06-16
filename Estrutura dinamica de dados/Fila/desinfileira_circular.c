#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u; // p= inicio d afila., u= fim da fila 
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        // A fila está vazia
        return 0;
    }

    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N; // A operação % (módulo) é usada para garantir que o índice permaneça dentro dos limites da fila circular.

    return 1;
}