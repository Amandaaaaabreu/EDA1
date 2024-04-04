#include <stdio.h>
#include <stdlib.h>

long int fibonacci(int n){
    if (n == 0)
        return n;
    else if (n == 1)
        return n; 
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}


int main(){

    int n = 11; 

    printf("Digite um numero inteiro: ");
    scanf("%d", &n); 

    printf("Fibonacci(%d) = %ld\n", n, fibonacci(n));

    return 0; 
}