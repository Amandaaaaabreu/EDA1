#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca os elementos
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int numeros[1000];
    int n = 0;

    // Lendo os números até o final do arquivo (EOF)
    while (scanf("%d", &numeros[n]) != EOF) {
        n++;
    }

    // Ordenando os números usando Selection Sort
    selectionSort(numeros, n);

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
