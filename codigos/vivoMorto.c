#include <stdio.h>
#include <stdlib.h>

int main() {
    int test_case = 1;

    while (1) {
        int P, R;
        scanf("%d %d", &P, &R);

        if (P == 0 && R == 0) break;

        int participants[P];
        for (int i = 0; i < P; i++) {
            scanf("%d", &participants[i]);
        }

        for (int r = 0; r < R; r++) {
            int N, J;
            scanf("%d %d", &N, &J);

            int actions[N];
            for (int i = 0; i < N; i++) {
                scanf("%d", &actions[i]);
            }

            int new_participants[N];
            int new_count = 0;
            for (int i = 0; i < N; i++) {
                if (actions[i] == J) {
                    new_participants[new_count++] = participants[i];
                }
            }

            for (int i = 0; i < new_count; i++) {
                participants[i] = new_participants[i];
            }
            P = new_count;
        }

        printf("Teste %d\n", test_case++);
        printf("%d\n\n", participants[0]);
    }

    return 0;
}
