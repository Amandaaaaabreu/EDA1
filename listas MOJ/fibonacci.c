#include <stdio.h>
#include <stdlib.h>


unsigned long int vetor[81];

long int fibonacci(int n){
    if ((n == 1 || n == 2 )){
        vetor[n]= 1; 
        return 1; 
    }

    if(n == 0){
        return 0; 
    }

    else (vetor[n] != 0);{
        vetor[n]= fibonacci(n-2) + fibonacci(n-1);
    }
        return vetor[n];

}
/*
int main(){

    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n); 

    printf("Fibonacci(%d) = %ld\n", n, fibonacci(n));

    return 0; 
}

*/