#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia
    if (f->u == f->N) {
        // Redimensiona o vetor dados
        int *novo_dados = (int *)realloc(f->dados, 2 * f->N * sizeof(int));
        if (novo_dados == NULL) {
            //printf("Erro ao redimensionar a fila.\n");
            return 0;
        }
        f->dados = novo_dados;
        f->N *= 2;
    }
    
    // Insere o elemento x na fila
    f->dados[f->u] = x;
    f->u++;
    
    return 1;
}