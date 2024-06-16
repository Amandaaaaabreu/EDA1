#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYWORD_LENGTH 16

// Estrutura para representar um nó da árvore
typedef struct Node {
    int code;
    char keyword[MAX_KEYWORD_LENGTH];
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó da árvore
Node* createNode(int code, const char* keyword) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->code = code;
    strcpy(newNode->keyword, keyword);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore
Node* insertNode(Node* root, int code, const char* keyword) {
    if (root == NULL) {
        return createNode(code, keyword);
    }

    if (code < root->code) {
        root->left = insertNode(root->left, code, keyword);
    } else if (code > root->code) {
        root->right = insertNode(root->right, code, keyword);
    }

    return root;
}

// Função para buscar uma palavra-chave na árvore
void search(Node* root, int code) {
    if (root == NULL) {
        printf("undefined\n");
        return;
    }

    if (root->code == code) {
        printf("%s\n", root->keyword);
    } else if (code < root->code) {
        search(root->left, code);
    } else {
        search(root->right, code);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;

    // Lendo as instruções e inserindo na árvore
    for (int i = 0; i < n; i++) {
        int code;
        char keyword[MAX_KEYWORD_LENGTH];
        scanf("%d %s", &code, keyword);
        root = insertNode(root, code, keyword);
    }

    // Buscando as instruções consultadas
    int query;
    while (scanf("%d", &query) != EOF) {
        search(root, query);
    }

    return 0;
}
