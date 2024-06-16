
#include <stdlib.h>

typedef struct pilha {
int *dados;
int N, topo;
} pilha;

int empilha(pilha *p, int x) {
    // Verificar se a pilha está cheia
    if (p->topo == p->N) {
        // Redimensionar o vetor dados
        int *newDados = realloc(p->dados, 2 * p->N * sizeof(int));
        if (newDados == NULL) {
            return 0; // Falha na alocação de memória
        }
        p->dados = newDados;
        p->N *= 2;
    }
    
    // Inserir o elemento x na pilha
    p->dados[p->topo] = x;
    p->topo++;
    
    return 1; // Inserção bem sucedida
}