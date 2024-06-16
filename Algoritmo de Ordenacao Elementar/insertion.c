#include <stdio.h>
#include <stdlib.h>

//otimizado
typedef struct item{
    int key;
} Item; 

//compara dois elemenos
int less(Item a, Item b){
    return a.key < b.key;
}

//troca dois elementos
void exch(Item *a, Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void cmpexch(Item *a, Item *b){
    if(less(*b, *a))
    exch (a, b);
}

void insertion_sort(Item *v, int l, int r){
    for(int i=r; i>l; i--)
    cmpexch(&v[i-1], &v[i]);

    for(int i=l+2; i<=r; i++){
        int j = i; 
        Item temp = v[j];
        while(less(temp, v[j-1])){
        v[j] = v[j-1]; 
        j--;
    }
        v[j] = temp; 
    }

}

int main(void){
     Item vetor[4000000]; 
    
    for(int i=0; i < 4000000; i++){
         vetor[i].key= rand();
    }
    insertion_sort(vetor,0,3999999);
    return 0; 
}