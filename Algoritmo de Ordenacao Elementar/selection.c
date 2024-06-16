#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int key; 
    // outros campos
}Item; 

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

void selection_sort(Item *v, int l, int r){
    if (l == r) return; //condicao de parada
    int min = l; 
    for(int j = l+1; j<=r; j++){
        if(less(v[j], v[min]))
            min = j;
    }

    exch (&v[min], &v[l]);
    selection_sort(v, l+1, r); 
}


int main(void){
    Item vetor[4000000]; 
    
    for(int i=0; i<4000000; i++){
         vetor[i].key= rand();
    }
    selection_sort(vetor,0,3999999);
    return 0; 
}