#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACTIONS 1000
#define STR_LEN 101

typedef struct {
    char actions[MAX_ACTIONS][STR_LEN];
    int top;
} UndoStack;

void push(UndoStack *s, const char *action) {
    if (s->top < MAX_ACTIONS - 1) {
        strcpy(s->actions[++s->top], action);
    }
}

char* pop(UndoStack *s) {
    if (s->top == -1) {
        return "NULL";
    } else {
        return s->actions[s->top--];
    }
}

int main() {
    UndoStack stack;
    stack.top = -1;
    char command[10], action[STR_LEN], line[STR_LEN + 10];

    while (fgets(line, sizeof(line), stdin)) {
        sscanf(line, "%s", command);
        if (strcmp(command, "inserir") == 0) {
            // Removendo o comando 'inserir ' para obter apenas a ação
            memmove(line, line + 8, strlen(line));
            line[strlen(line) - 1] = '\0';  // Removendo o newline no final
            push(&stack, line);
        } else if (strcmp(command, "desfazer") == 0) {
            printf("%s\n", pop(&stack));
        }
    }

    return 0;
}