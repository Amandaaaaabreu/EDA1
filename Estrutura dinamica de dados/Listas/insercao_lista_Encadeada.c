#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;
    
    void insere_inicio (celula *le, int x) {
        celula *nova = malloc(sizeof(celula));
        if (nova == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        nova->dado = x;
        nova->prox = le->prox;
        le->prox = nova;
    }

    void insere_antes (celula *le, int x, int y) {
        celula *nova = malloc(sizeof(celula));
        if (nova == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        nova->dado = x;

        while (le->prox != NULL && le->prox->dado != y) {
            le = le->prox;
        }

        nova->prox = le->prox;
        le->prox = nova;
    }