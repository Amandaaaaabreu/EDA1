#include <stdio.h>
#include <stdlib.h>

// implementando uma função recursiva que, dada dois numeros inteiros calcula e retorna o valor
// caso base, if j = 0 

int potencia (int i, int j){
    if (j == 0){
        return 1; 
    }
    else {
        return i * potencia (i, j-1);
    }
}

int main(){

    int i, j; 

    printf("Digite o valor para X e para N: ");
    scanf("%d%d", &i, &j );

    printf("Resultado de %d elevado a %d: %d ",i, j, potencia(i,j) );

    return 0;
}


