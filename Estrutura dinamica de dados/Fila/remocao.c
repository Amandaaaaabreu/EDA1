#include <stdio.h> 
#include <stdlib.h>

typedef struct fila {
    int *dado; 
    int N, p, u;
} fila; 

int desenfileira(fila *f, int *y) {  //removendo da fila 
    if (f->p == f->u) {
        return 0;
    }
    
    *y = f->dado[f->p];
    f->p++; 
    
    return 1;
}
