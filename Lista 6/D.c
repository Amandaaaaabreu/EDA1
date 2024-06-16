#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int numeros[1000];
    int n = 0;

    // Lendo os números até o final do arquivo (EOF)
    while (scanf("%d", &numeros[n]) != EOF) {
        n++;
    }

    // Ordenando os números usando Bubble Sort
    bubbleSort(numeros, n);

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
