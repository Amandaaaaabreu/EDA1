#include <stdio.h>

int main() {
    int C, T;
    scanf("%d %d", &C, &T);
    
    // Array para armazenar os raios dos círculos
    int raios[C];
    
    // Lendo os raios dos círculos
    for (int i = 0; i < C; i++) {
        scanf("%d", &raios[i]);
    }
    
    // Variável para armazenar a pontuação total
    int pontuacao = 0;
    
    // Verificando a pontuação para cada tiro
    for (int i = 0; i < T; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        // Verificando se o tiro está dentro de algum círculo
        for (int j = 0; j < C; j++) {
            if (x * x + y * y <= raios[j] * raios[j]) {
                pontuacao += (C - j);
                break;
            }
        }
    }
    
    // Imprimindo a pontuação total
    printf("%d\n", pontuacao);
    
    return 0;
}
