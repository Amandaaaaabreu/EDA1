#include <stdio.h>
#include <stdlib.h>

#define MAX_HOUSES 45000

// Estrutura para representar uma casa
typedef struct {
    int house_number;
    int position;
} House;

// Função de comparação para ordenar as casas pelo número
int compare_houses(const void *a, const void *b) {
    const House *house_a = (const House *)a;
    const House *house_b = (const House *)b;
    return house_a->house_number - house_b->house_number;
}

// Função para encontrar a posição de uma casa na rua
int find_house_position(int house_number, House *houses, int num_houses) {
    for (int i = 0; i < num_houses; i++) {
        if (houses[i].house_number == house_number) {
            return houses[i].position;
        }
    }
    return -1; // Se a casa não for encontrada
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    House houses[MAX_HOUSES];

    // Lendo e armazenando as casas
    for (int i = 0; i < N; i++) {
        scanf("%d", &houses[i].house_number);
        houses[i].position = i;
    }

    // Ordenando as casas pelo número
    qsort(houses, N, sizeof(House), compare_houses);

    int current_position = 0; // Começamos na primeira casa
    int total_time = 0;

    // Processando as encomendas
    for (int i = 0; i < M; i++) {
        int destination_house;
        scanf("%d", &destination_house);
        int destination_position = find_house_position(destination_house, houses, N);
        
        // Calculando o tempo para ir da posição atual até a posição da casa de destino
        int travel_time = abs(destination_position - current_position);
        total_time += travel_time;
        current_position = destination_position;
    }

    printf("%d\n", total_time);

    return 0;
}
