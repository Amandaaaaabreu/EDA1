#include <stdio.h>
//#include <stdlib.h>

// argc é um inteiro que armazena a quantidade de argumentos informados pelo usuário, incluindo o nome do programa.

// argv é um vetor de ponteiros para char listando todos os argumentos.


int main(int argc, char **argv ){
    int i; 
    printf("%d\n", argc -1 );

    for(i =1; i < argc; i++){
        printf("%s\n", argv[i]);
    }



    return 0;
}