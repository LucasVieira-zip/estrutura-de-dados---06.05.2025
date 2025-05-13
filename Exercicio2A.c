#include <stdio.h>
#include <string.h>

#define MAX_PAGINAS 5
#define TAMANHO_URL 100

typedef struct {
    char urls[MAX_PAGINAS][TAMANHO_URL];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PAGINAS - 1;
}

void empilhar(Pilha *p, char url[]) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    strcpy(p->urls[p->topo], url);
}

void desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Nao ha mais paginas para voltar!\n");
        return;
    }
    printf("Voltando para: %s\n", p->urls[p->topo - 1]);
    p->topo--;
}

void mostrarPaginaAtual(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Nenhuma pagina carregada.\n");
        return;
    }
    printf("Pagina atual: %s\n", p->urls[p->topo]);
}

int main() {
    Pilha navegador;
    inicializarPilha(&navegador);
    char url[TAMANHO_URL];
    int opcao;

    printf("Digite as 5 paginas visitadas:\n");
    for (int i = 0; i < MAX_PAGINAS; i++) {
        printf("Pagina %d: ", i + 1);
        scanf("%s", url);
        empilhar(&navegador, url);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Mostrar pagina atual\n");
        printf("2. Voltar\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarPaginaAtual(&navegador);
                break;
            case 2:
                desempilhar(&navegador);
                break;
            case 3:
                printf("Encerrando navegador...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}