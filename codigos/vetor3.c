#include <stdio.h>
#include <stdlib.h>
#include <time.h> // armazena a hora do computador

// Como gerar numeros aleatorios para preencher um vetor

int main(){
    int i;
    int num [17];

    srand(time(NULL));  //inicializando a semente para gerar numeros pseudo aleatorios para a funcao rand atraves das horas do computador 

    for( i = 0; i < 17; i++){
        num[i] = 1 + rand() % 55; // gerando numeros pseudo aleatorios com a funcao rand (limite de 1 - 55)

    }printf("\n");


    for(i = 0; i < 17; i++){
        printf("%d ", num[i]);

    }printf("\n\n");

    return 0;


}

