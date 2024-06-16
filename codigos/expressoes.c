#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para verificar se a cadeia de caracteres é bem definida
int isWellDefined(const char *str) {
    int len = strlen(str);
    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == '{' || c == '[' || c == '(') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                return 0; // Pilha vazia mas encontrou um caracter de fechamento
            }
            char topChar = stack[top--];
            if ((c == '}' && topChar != '{') || 
                (c == ']' && topChar != '[') || 
                (c == ')' && topChar != '(')) {
                free(stack);
                return 0; // Não casou corretamente
            }
        }
    }

    int result = (top == -1) ? 1 : 0; // Verifica se a pilha está vazia no final
    free(stack);
    return result;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char str[100001];
        scanf("%s", str);
        if (isWellDefined(str)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
