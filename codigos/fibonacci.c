#include <stdio.h> 
#include <stdlib.h>

 // menos eficiente 
 


int fibonacci(int n){
    if (n == 1){
        return 0; 
    }
    else if (n == 2){
        return 1; 
   }
   else 
        return fibonacci(n-1) + fibonacci(n-2);  // chamada recursiva 
}

// 1 2 3 4 5 6 7
// 0 1 1 2 3 5 8
int main(){

    int n;

    printf("Digite um valor maior que zero: ");
    scanf("%d", &n);

    

    printf("O termo %d e: %d ", n,fibonacci(n));
    return 0;
}