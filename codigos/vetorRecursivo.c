#include <stdio.h>
#include <stdlib.h>

// função recursiva para calcular a soma de todos os elementos de um vator de inteiros

int soma(int v[], int tam){
    if (tam == 0){  // caso base
        return 0; 
    }else{
        return v[tam - 1] + soma(v, tam -1);
    }

}

int main(){
    int vet[10] = {1,2,3,4,5,6,7,8,9,10};
   

    printf("A soma do vetor sera: %d\n", soma(vet, 10));

    return 0;
}