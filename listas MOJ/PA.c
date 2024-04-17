#include <stdio.h>
#include <stdlib.h> 

int pa_recursiva(int *v, int primeiro, int ultimo){
    if (primeiro >= ultimo){   // caso base: se [0]> [1] = todos os vetores foram verificados 
        return 1; 
    }else{
        if (v[primeiro]+ v[ultimo] == v[primeiro +1] + v[ultimo -1]){ // verificando se a soma do primeiro e ultimo elemento é igual ao segundo e penultimo...
            return  pa_recursiva(v, primeiro +1, ultimo -1); // ...e assim por diante, verificando se a soma do terceiro e antipenultimo é igual aos anteriores. 
    }else {
        return 0; // não é uma PA
        }
    }
 }


