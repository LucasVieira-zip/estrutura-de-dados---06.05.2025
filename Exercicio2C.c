#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia!\n");
        return '\0';
    }
    return s->data[s->top--];
}

void invertWord(char *word) {
    Stack s;
    initialize(&s);
    int length = strlen(word);

    // Empilha cada caractere da palavra
    for (int i = 0; i < length; i++) {
        push(&s, word[i]);
    }

    // Desempilha para inverter a palavra
    for (int i = 0; i < length; i++) {
        word[i] = pop(&s);
    }
}

int main() {
    char word[MAX_SIZE];

    printf("Digite uma palavra: ");
    scanf("%s", word);

    invertWord(word);

    printf("Palavra invertida: %s\n", word);

    return 0;
}