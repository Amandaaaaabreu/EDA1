#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        // Move os elementos do arr[0..i-1] que são maiores que a chave para uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int numeros[50000];
    int n = 0;

    // Lendo os números até o final do arquivo (EOF)
    while (scanf("%d", &numeros[n]) != EOF) {
        n++;
    }

    // Ordenando os números usando Insertion Sort
    insertionSort(numeros, n);

    // Imprimindo os números ordenados
    for (int i = 0; i < n; i++) {
        printf("%d", numeros[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
