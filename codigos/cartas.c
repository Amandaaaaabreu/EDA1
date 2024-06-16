#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para a fila
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Função para criar um novo nó
Node* newNode(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

// Função para criar uma fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para enfileirar (inserir no final da fila)
void enqueue(Queue* q, int value) {
    Node* temp = newNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Função para desenfileirar (remover do início da fila)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int value = temp->value;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

// Função principal para resolver o problema
void solve(int n) {
    Queue* q = createQueue();
    int discarded[n];
    int discarded_count = 0;

    // Inicializa a fila com cartas de 1 a n
    for (int i = 1; i <= n; i++) {
        enqueue(q, i);
    }

    // Processa a fila até restar apenas uma carta
    while (q->front != q->rear) {
        discarded[discarded_count++] = dequeue(q); // Descartar a carta do topo
        enqueue(q, dequeue(q)); // Mover a próxima carta para a base
    }

    // A última carta restante
    int remaining_card = dequeue(q);

    // Imprime os resultados
    printf("Cartas descartadas: ");
    for (int i = 0; i < discarded_count; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", discarded[i]);
    }
    printf("\nCarta restante: %d\n", remaining_card);
}

int main() {
    int n;
    printf("");
    scanf("%d", &n);

    if (n >= 2) {
        solve(n);
    }

    return 0;
}
