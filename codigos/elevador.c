#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 1000000
#define INF 1000001  // Valor maior que o número máximo de andares

typedef struct {
    int floor;
    int presses;
} Node;

typedef struct {
    Node* array;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int maxSize) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (Node*)malloc(maxSize * sizeof(Node));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, Node node) {
    queue->rear = (queue->rear + 1) % MAX_FLOORS;
    queue->array[queue->rear] = node;
    queue->size++;
}

Node dequeue(Queue* queue) {
    Node node = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_FLOORS;
    queue->size--;
    return node;
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    if (s == g) {
        printf("0\n");
        return 0;
    }

    int* visited = (int*)calloc(f + 1, sizeof(int));
    Queue* queue = createQueue(f + 1);

    // Inicializar a fila com o andar inicial
    Node start = {s, 0};
    enqueue(queue, start);
    visited[s] = 1;

    while (!isEmpty(queue)) {
        Node current = dequeue(queue);

        // Tentar subir
        if (current.floor + u <= f && !visited[current.floor + u]) {
            if (current.floor + u == g) {
                printf("%d\n", current.presses + 1);
                free(visited);
                freeQueue(queue);
                return 0;
            }
            Node nextUp = {current.floor + u, current.presses + 1};
            enqueue(queue, nextUp);
            visited[current.floor + u] = 1;
        }

        // Tentar descer
        if (current.floor - d >= 1 && !visited[current.floor - d]) {
            if (current.floor - d == g) {
                printf("%d\n", current.presses + 1);
                free(visited);
                freeQueue(queue);
                return 0;
            }
            Node nextDown = {current.floor - d, current.presses + 1};
            enqueue(queue, nextDown);
            visited[current.floor - d] = 1;
        }
    }

    printf("use the stairs\n");

    free(visited);
    freeQueue(queue);
    return 0;
}
