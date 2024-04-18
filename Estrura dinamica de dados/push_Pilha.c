#include <stdio.h>
#include <stlib.h>

//Estrura de dados dinamicas 


typedef struct{
    int dia, mes, ano; 
}Data; 


typedef struct{
    char nome [50];
    Data data; 
}Pessoa; 

typedef struct no {
    Pessoa p; 
    struct no *proximo; // ponteiro para o proximo no 
}No; // nome que eu quiser pra minha estrutura

Pessoa_ler_pessoa(){
    Pessoa p; 
    printf("\nDigite nome data de nascimento dd mm aaaa: \n ");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}
 void imprimir_pessoa (Pessoa p ){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, pdata.dia, p.data.mes, p.data.ano);
 }

 // FUNCAO PARA A OPERAÇÃO PUSH (EMPILHAR )

No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));

    if (novo){
        novo -> p = ler_pessoa();
        novo -> proximo = topo;
        return novo;
    }else 
        printf("\n\nNao foi possivel alocar memoria\n");
    return NULL; 
}

 int main(){

     No *topo = NULL; // toda operação de uma pilha fazemos no topo 
     int opcao;

     do {
        printf("\n0 - Sair\n1 - Empilar\n2 - Desempilha\n3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1: 
            topo = empilhar(topo);
            break;
        case 2: 
        

            break;
        case 3: 

            break;
        default:
            if(opcapo != 0)
            printf("\nOpcao invalida\n");
        }
      
     }      while(opcao != 0 );  
                return 0; 
 }