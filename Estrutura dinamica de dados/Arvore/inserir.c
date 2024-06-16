#include <stdio.h> 
#include <stdlib.h> 

/* Como inserir em uma arvore binaria?

       50 raiz
    25     100
      30

*/

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv; 

NoArv* inserir_versao_1(NoArv *raiz, int num){  // funcao recursiva 
    if(raiz == NULL){
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL; 
        return aux;
    }else {
        if(num < raiz->valor)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, num);
        else
            raiz->direita = inserir_versao_1(raiz->direira, num);
        return raiz; 
    }
}

int main(){
    NoArv *raiz = NULL; 

    raiz = inserir_versao_1(raiz, 50);

    return 0;
}