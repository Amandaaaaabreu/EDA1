#include <stdio.h>
#include <stdlib.h>

// Estrutura para os nós das listas encadeadas
typedef struct Node {
    int col;
    int value;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função para multiplicar a matriz esparsa pelo vetor
void sparseMatrixVectorMultiplication(Node** matrix, int m, int* vector, int* result) {
    for (int i = 0; i < m; i++) {
        result[i] = 0;
        Node* current = matrix[i];
        while (current != NULL) {
            result[i] += current->value * vector[current->col];
            current = current->next;
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // Alocar memória para a matriz esparsa (lista de listas encadeadas)
    Node** matrix = (Node**)malloc(m * sizeof(Node*));
    for (int i = 0; i < m; i++) {
        matrix[i] = NULL;
    }

    // Ler a matriz esparsa
    int row, col, value;
    while (1) {
        scanf("%d %d %d", &row, &col, &value);
        if (row == -1 && col == -1 && value == -1) {
            break;
        }
        Node* newNode = createNode(col, value);
        newNode->next = matrix[row];
        matrix[row] = newNode;
    }

    // Ler o vetor
    int* vector = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    // Alocar memória para o resultado
    int* result = (int*)malloc(m * sizeof(int));

    // Calcular a multiplicação matriz-vetor
    sparseMatrixVectorMultiplication(matrix, m, vector, result);

    // Imprimir o resultado
    for (int i = 0; i < m; i++) {
        printf("%d\n", result[i]);
    }

    // Liberar memória
    for (int i = 0; i < m; i++) {
        Node* current = matrix[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
