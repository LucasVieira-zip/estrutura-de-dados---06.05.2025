#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->data[s->top--];
}

bool isBalanced(char expression[]) {
    Stack s;
    initialize(&s);
    
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') {
            push(&s, expression[i]);
        } else if (expression[i] == ')') {
            if (isEmpty(&s)) {
                return false;
            }
            pop(&s);
        }
    }
    
    return isEmpty(&s);
}

int main() {
    char expression[MAX_SIZE];
    
    printf("Digite uma expressao matematica: ");
    fgets(expression, MAX_SIZE, stdin);
    
    // Remove o caractere de nova linha (\n) do final
    expression[strcspn(expression, "\n")] = '\0';
    
    if (isBalanced(expression)) {
        printf("Os parenteses estao balanceados!\n");
    } else {
        printf("Os parenteses NAO estao balanceados!\n");
    }
    
    return 0;
}