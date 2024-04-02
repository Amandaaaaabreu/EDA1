#include <stdio.h> 

int fat(int n){
    if (n)
    return n = n*fat(n-1); // enquanto n não for = 0 a fução fat é chamada
    else
    return 1; // condição de parada
}

int main(){
    int n; 
    printf("Digite o valor de n: \n");
    scanf("%d", &n);
    printf("O fatorial de %d e %d", n, fat(n));
    return 0; 
}


