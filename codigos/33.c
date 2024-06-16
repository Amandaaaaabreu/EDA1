#include <stdio.h>

int numPontos, numConsultas;
long long int raiosQuadrados[100010];

int buscaBinaria(long long int valorBuscado){
    int inicio = 1;
    int fim = numPontos;
    if(valorBuscado > raiosQuadrados[numPontos])	return 0;

    while(inicio < fim){
        int meio = (inicio + fim) / 2;

        if(raiosQuadrados[meio] >= valorBuscado){
            fim = meio;
        }
        else{
            inicio = meio + 1;
        }
    }
    return numPontos + 1 - fim;
}


int main(){

    scanf("%d %d", &numPontos, &numConsultas);

    for(int i = 1; i <= numPontos; i++){
        scanf("%lld", &raiosQuadrados[i]);
        raiosQuadrados[i] *= raiosQuadrados[i];
    }

    long long int somaResultados = 0;

    for(int i = 1; i <= numConsultas; i++){
        long long int coordX, coordY;
        scanf("%lld %lld", &coordX, &coordY);

        somaResultados += buscaBinaria(coordX*coordX + coordY*coordY);
    }

    printf("%lld\n", somaResultados);

    return 0;
}