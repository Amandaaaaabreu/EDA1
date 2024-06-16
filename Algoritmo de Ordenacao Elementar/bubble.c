#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int key;
} Item; 

// comparar os dois itens
int less(Item a, Item b){
    return a.key < b.key;
}

// trocar os dois itens
void exch (Item *a, Item *b){
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// trocar e comparar os dois itens
void cmpexch(Item *a, Item *b) {
    if (less(*b, *a))
        exch(a, b);
}

void bubble_sort(Item *v, int l, int r){
    int j;
    for (int i=l; i<r; i++)
        for(j=l; j<r; j++){
            cmpexch(&v[j], &v[j+1]);
        }
}

int main(void){
     Item vetor[10000]; 
    
    for(int i=0; i < 10000; i++){
         vetor[i].key= rand();
    }
    bubble_sort(vetor,0,9999);
    return 0; 
}
