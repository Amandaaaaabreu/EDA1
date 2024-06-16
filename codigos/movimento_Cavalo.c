#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Movimentos possíveis do cavalo no tabuleiro de xadrez
int knight_moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    int moves;
} Node;

typedef struct {
    Node *array;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (Node*)malloc(capacity * sizeof(Node));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Node item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

Node dequeue(Queue* queue) {
    Node item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void freeQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

// Verifica se a posição está dentro dos limites do tabuleiro
int isValid(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

// Converte a posição do formato "e2" para coordenadas (x, y)
Position convertToPosition(char *pos) {
    Position p;
    p.x = pos[0] - 'a';
    p.y = pos[1] - '1';
    return p;
}

// Função para encontrar o menor número de movimentos do cavalo
int bfs(Position start, Position end) {
    if (start.x == end.x && start.y == end.y) {
        return 0;
    }

    int visited[BOARD_SIZE][BOARD_SIZE] = {{0}};
    Queue* queue = createQueue(BOARD_SIZE * BOARD_SIZE);

    Node startNode = {start, 0};
    enqueue(queue, startNode);
    visited[start.x][start.y] = 1;

    while (!isEmpty(queue)) {
        Node current = dequeue(queue);

        for (int i = 0; i < 8; i++) {
            int newX = current.pos.x + knight_moves[i][0];
            int newY = current.pos.y + knight_moves[i][1];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                if (newX == end.x && newY == end.y) {
                    freeQueue(queue);
                    return current.moves + 1;
                }

                visited[newX][newY] = 1;
                Node nextNode = {{newX, newY}, current.moves + 1};
                enqueue(queue, nextNode);
            }
        }
    }

    freeQueue(queue);
    return -1;  // Não deveria chegar aqui, pois sempre há uma solução
}

int main() {
    char start[3], end[3];
    int test_case = 1;

    while (scanf("%s %s", start, end) != EOF) {
        Position startPos = convertToPosition(start);
        Position endPos = convertToPosition(end);

        int moves = bfs(startPos, endPos);

        printf("To get from %s to %s takes %d knight moves.\n", start, end, moves);
        test_case++;
    }

    return 0;
}
