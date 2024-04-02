#include <stdio.h>
#include <stdlib.h>

// função recursiva que encontre e retorne o maior elemento de um vetor de inteiros do tamanho N 

int maior (int v[], int tam, int indice){
    if (tam == 0){
        return v[indice]; 
    }else{
        if (v[tam-1] > v[indice]){
            return maior(v, tam - 1, tam - 1);
        } 
        else{
            return maior(v, tam - 1, indice);
        }
    }
        
    
}

int main(){
    int vet[10] = {1,2,33,4,5,60,700,8,94,10};
   
    printf("Maior elemento do vetor: %d\n", maior(vet, 10, 0) );

    return 0;
}