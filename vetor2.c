#include <stdio.h>

// Como alterar o conteúdo de um vetor 

int main(){
    int i;
    int num2 [10];

    for (i = 0; i < 10; i++){
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &num2[i]);

    }printf("\n");


    for(i = 0; i< 10; i++){
       num2 [i] = num2[i] * 3;  // pegando o elemento da posicao i multiplicando por 3 e salvando o resultado na mesma posicao
    }
    

    for(i = 0; i < 10; i++){
        printf("%d ", num2[i]);
    }printf("\n\n");

    return 0;
}