#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        // A fila está vazia
        return 0;
    }

    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N;

    return 1;
}