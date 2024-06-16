#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar as informações de cada pista
typedef struct {
    int value;
    int next;
} Track;

int main() {
    int n;
    scanf("%d", &n);

    // Alocar memória para armazenar as pistas
    Track *tracks = (Track *)malloc(5001 * sizeof(Track));
    int firstTrackId, firstTrackValue, firstTrackNext;

    // Ler as pistas
    for (int i = 0; i < n; i++) {
        int id, value, next;
        scanf("%d %d %d", &id, &value, &next);
        tracks[id].value = value;
        tracks[id].next = next;
        if (i == 0) {
            firstTrackId = id;
            firstTrackValue = value;
            firstTrackNext = next;
        }
    }

    // Percorrer a lista encadeada a partir da primeira pista e imprimir os valores
    int currentId = firstTrackId;
    while (currentId != -1) {
        printf("%d\n", tracks[currentId].value);
        currentId = tracks[currentId].next;
    }

    // Liberar memória
    free(tracks);

    return 0;
}