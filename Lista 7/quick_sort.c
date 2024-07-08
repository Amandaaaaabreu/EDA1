#include <stdio.h>
#include <stdlib.h>

// Função para fazer a mesclagem de dois subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copiando os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mesclando os arrays temporários de volta para arr[left..right]
    i = 0; // Índice inicial para o subarray esquerdo
    j = 0; // Índice inicial para o subarray direito
    k = left; // Índice inicial para o subarray mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função de ordenação Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontra o ponto médio
        int mid = left + (right - left) / 2;

        // Ordena as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Chama a função de ordenação Merge Sort
    mergeSort(arr, 0, n - 1);

    // Imprime o array ordenado
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
