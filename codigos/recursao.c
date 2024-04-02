#include <stdio.h> 
#include <stdlib.h>

// imprimindo os numeros de n até 0

void imprimir(int x){
    if ( x == 0)
        printf("%d ", x);
    else {
        imprimir(x-1);
        printf("%d ", x);
        
    }
}
int main(){
    int n; 
    printf("Digite um valor maior que 0: ");
    scanf("%d", &n); 

    imprimir(n);
    
    return 0; 
}