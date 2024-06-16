#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pre_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }
    
    no *pilha[100]; // Pilha para armazenar os nós
    int topo = -1; // Índice do topo da pilha
    
    pilha[++topo] = raiz; // Empilha a raiz
    
    while (topo >= 0) {
        no *no_atual = pilha[topo--]; // Desempilha o nó atual
        
        printf("%d ", no_atual->dado); // Imprime o valor do nó
        
        // Empilha o nó da direita antes do nó da esquerda
        if (no_atual->dir != NULL) {
            pilha[++topo] = no_atual->dir;
        }
        if (no_atual->esq != NULL) {
            pilha[++topo] = no_atual->esq;
        }
    }
}

