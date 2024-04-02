#include <stdio.h> 
#include <stdlib.h> 


int soma (int n){
    if ( n == 0){
        return 0; 
    }else {
        return n + soma(n-1);
    }
}

int main(){
    int n;
    printf("Digite um numero para N: ");
    scanf("%d", &n); 

    printf("A soma de 1 ate %d foi: %d\n", n, soma(n));
    return 0;
}