#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira (fila *f, int x) {
  // Verifica se a fila está cheia
  if (f->u == f->N) {
    // Redimensiona o vetor de dados se necessário
    int *novo_dados = realloc(f->dados, 2 * f->N * sizeof(int));
    if (novo_dados == NULL) {
      return 0; // Falha na realocação
    }

    // Atualiza os ponteiros e tamanho do vetor
    f->dados = novo_dados;
    f->N = 2 * f->N;
  }

  // Insere o elemento no final da fila
  f->dados[f->u] = x;
  f->u = (f->u + 1) % f->N;

  return 1; // Sucesso na inserção
}