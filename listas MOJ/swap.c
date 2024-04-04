#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b){
    int temp; 
    temp = *a; 
    *a = *b;
    *b = temp; 
}
/*
int main(){
    int a, b;

    printf("Insira dois numeros inteiros:");
    scanf("%d%d", &a, &b);

    swap(&a, &b);

    printf("Troca realizada: %d %d\n ", a, b);

    return 0; 
}
*/

