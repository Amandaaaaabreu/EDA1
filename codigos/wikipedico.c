#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100001

char validateText(int N, char lines[][MAX_LENGTH]) {
    char stack[MAX_LENGTH];
    int top = -1;

    for (int i = 0; i < N; i++) {
        int len = strlen(lines[i]);

        for (int j = 0; j < len; j++) {
            char ch = lines[i][j];
            if (ch == '*' || ch == '/' || ch == '_') {
                if (top == -1 || stack[top] != ch) {
                    stack[++top] = ch;
                } else {
                    top--;
                }
            }
        }
    }

    return (top == -1) ? 'C' : 'E';
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char lines[MAX_LINES][MAX_LENGTH];

    for (int i = 0; i < N; i++) {
        fgets(lines[i], MAX_LENGTH, stdin);
        lines[i][strcspn(lines[i], "\n")] = 0;
    }

    char result = validateText(N, lines);
    printf("%c\n", result);

    return 0;
}