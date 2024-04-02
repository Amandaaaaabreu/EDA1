#include <stdio.h>

// Conjunto de elementos do mesmo tipo (estrutura de dados homogenea)

int main() {
    int matriz1[6][4] = {    // linha (i), coluna(j)
        {1, 2, 3, 6},
        {4, 5, 6, 7},
        {7, 8, 9, 8},
        {7, 8, 9, 2},
        {7, 8, 9, 2},
        {7, 8, 9, 2},
    };


    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");

    }printf("\n");

     int matriz2[3][4] = {    // linha (i), coluna(j)
        {1, 2, 3, 6},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
       
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");

    }printf("\n");

    int matriz3 [4][5] = {           // linha (i), coluna(j)
        {1, 2, 3, 8, 7},
        {4, 5, 6, 2, 3},
        {7, 8, 9, 5, 9},
        {7, 8, 9, 5, 9}

    };

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 5; j++){
                printf("%d ", matriz3[i][j]);
            }
            printf("\n");

        } printf("\n");

        int matriz4 [2][2] = {0, 5, 6, 7};

        for (int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++ )
                printf("%d", matriz4[i][j]);

                printf("\n");
        };


        char matriz5[3][3] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

        for(int i = 0; i< 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%c", matriz5[i][j]);
            }

            printf("\n");
        }

    

    return 0;
}