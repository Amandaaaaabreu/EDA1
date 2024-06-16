#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;

    while (1) {
        // Ler o número de caminhões
        scanf("%d", &n);
        if (n == 0) break;

        int trucks[MAX];
        for (int i = 0; i < n; i++) {
            scanf("%d", &trucks[i]);
        }

        int stack[MAX];
        int top = -1;
        int next = 1;
        int possible = 1;

        for (int i = 0; i < n; i++) {
            while (top != -1 && stack[top] == next) {
                top--;
                next++;
            }
            if (trucks[i] == next) {
                next++;
            } else if (top == -1 || stack[top] > trucks[i]) {
                stack[++top] = trucks[i];
            } else {
                possible = 0;
                break;
            }
        }

        printf("%s\n", possible ? "yes" : "no");
    }

    return 0;
}
