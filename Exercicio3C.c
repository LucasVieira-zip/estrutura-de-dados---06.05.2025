#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PESSOAS 100

typedef struct {
    int idade;
    // Poderia adicionar mais campos como nome, etc.
} Pessoa;

typedef struct {
    Pessoa dados[MAX_PESSOAS];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

bool filaVazia(Fila *f) {
    return f->fim < f->inicio;
}

bool filaCheia(Fila *f) {
    return f->fim - f->inicio + 1 == MAX_PESSOAS;
}

void enfileirar(Fila *f, Pessoa p) {
    if (filaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->dados[++f->fim] = p;
}

Pessoa desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        Pessoa vazia = {-1};
        return vazia;
    }
    return f->dados[f->inicio++];
}

void atenderComPrioridade(Fila *normal, Fila *preferencial) {
    printf("\nIniciando atendimento:\n");
    
    // Primeiro atende todas as pessoas preferenciais
    while (!filaVazia(preferencial)) {
        Pessoa p = desenfileirar(preferencial);
        printf("Atendendo [PREFERENCIAL] - Idade: %d\n", p.idade);
    }
    
    // Depois atende as pessoas normais
    while (!filaVazia(normal)) {
        Pessoa p = desenfileirar(normal);
        printf("Atendendo [NORMAL] - Idade: %d\n", p.idade);
    }
    
    printf("Todos foram atendidos.\n");
}

int main() {
    Fila normal, preferencial;
    inicializarFila(&normal);
    inicializarFila(&preferencial);
    
    int quantidade;
    printf("Quantas pessoas na fila? ");
    scanf("%d", &quantidade);
    
    for (int i = 0; i < quantidade; i++) {
        Pessoa p;
        printf("Idade da pessoa %d: ", i + 1);
        scanf("%d", &p.idade);
        
        if (p.idade >= 60) {
            enfileirar(&preferencial, p);
        } else {
            enfileirar(&normal, p);
        }
    }
    
    atenderComPrioridade(&normal, &preferencial);
    
    return 0;
}