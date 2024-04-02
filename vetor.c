#include <stdio.h>
#include <stdlib.h>


int main(){
    int lista [5] = {1,5,9,7,8};

    for(int i = 0; i < 5; i++){
        printf("%d ", lista[i]);

    } printf("\n\n");

    float num[] = {7.8,8.7,9.7,3.1};
    int tamanho = 4;

    for(int i = 0; i < tamanho; i++){
        printf("%.1f ", num[i]);

    }printf("\n\n");

    char vogal[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++){
        printf("%c ", vogal[i]);
    }


}
