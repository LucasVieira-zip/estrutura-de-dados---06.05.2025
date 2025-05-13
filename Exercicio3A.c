#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

typedef struct {
    int senhas[TAMANHO_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

int filaVazia(Fila *f) {
    return f->quantidade == 0;
}

int filaCheia(Fila *f) {
    return f->quantidade == TAMANHO_FILA;
}

void enfileirar(Fila *f, int senha) {
    if (filaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % TAMANHO_FILA;
    f->senhas[f->fim] = senha;
    f->quantidade++;
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int senha = f->senhas[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_FILA;
    f->quantidade--;
    return senha;
}

void gerarSenhas(Fila *f) {
    srand(time(NULL));
    for (int i = 0; i < TAMANHO_FILA; i++) {
        int senha = rand() % 9000 + 1000; // Gera senhas de 4 dígitos
        enfileirar(f, senha);
    }
}

void atenderSenhas(Fila *f) {
    printf("\nIniciando atendimento:\n");
    while (!filaVazia(f)) {
        int senha = desenfileirar(f);
        printf("Atendendo senha %d\n", senha);
    }
    printf("Todas as senhas foram atendidas.\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    gerarSenhas(&fila);
    atenderSenhas(&fila);

    return 0;
}