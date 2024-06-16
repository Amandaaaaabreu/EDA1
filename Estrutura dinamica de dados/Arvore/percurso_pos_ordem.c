#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Estrutura da pilha
typedef struct stackNode {
    no* treeNode;
    struct stackNode* next;
} stackNode;

// Função para criar um novo nó na árvore
no* criarNo(int dado) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->dado = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

// Função para empilhar um nó da árvore na pilha
void push(stackNode** topo, no* treeNode) {
    stackNode* novoStackNode = (stackNode*)malloc(sizeof(stackNode));
    novoStackNode->treeNode = treeNode;
    novoStackNode->next = *topo;
    *topo = novoStackNode;
}

// Função para desempilhar um nó da árvore da pilha
no* pop(stackNode** topo) {
    if (*topo == NULL) {
        return NULL;
    }
    stackNode* temp = *topo;
    *topo = (*topo)->next;
    no* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

// Função para verificar se a pilha está vazia
int isEmpty(stackNode* topo) {
    return topo == NULL;
}

// Função para o percurso pós-ordem sem recursão
void pos_ordem(no *raiz) {
    if (raiz == NULL) {
        return;
    }

    stackNode* pilha1 = NULL;
    stackNode* pilha2 = NULL;

    push(&pilha1, raiz);
    while (!isEmpty(pilha1)) {
        no* atual = pop(&pilha1);
        push(&pilha2, atual);
        
        if (atual->esq) {
            push(&pilha1, atual->esq);
        }
        if (atual->dir) {
            push(&pilha1, atual->dir);
        }
    }

    while (!isEmpty(pilha2)) {
        no* atual = pop(&pilha2);
        printf("%d ", atual->dado);
    }
    printf("\n");
}


