#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_FILA 4

typedef struct {
    char documentos[TAMANHO_FILA][50]; // Armazena nomes de documentos
    int inicio;
    int fim;
    int quantidade;
} FilaImpressora;

void inicializarFila(FilaImpressora *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

bool filaVazia(FilaImpressora *f) {
    return f->quantidade == 0;
}

bool filaCheia(FilaImpressora *f) {
    return f->quantidade == TAMANHO_FILA;
}

void enfileirar(FilaImpressora *f, const char *documento) {
    if (filaCheia(f)) {
        printf("Fila de impressao cheia! Documento '%s' nao pode ser adicionado.\n", documento);
        return;
    }
    
    f->fim = (f->fim + 1) % TAMANHO_FILA;
    snprintf(f->documentos[f->fim], 50, "%s", documento);
    f->quantidade++;
    
    printf("Documento '%s' adicionado a fila.\n", documento);
}

void desenfileirar(FilaImpressora *f) {
    if (filaVazia(f)) {
        printf("Nenhum documento para imprimir.\n");
        return;
    }
    
    printf("Imprimindo: %s\n", f->documentos[f->inicio]);
    f->inicio = (f->inicio + 1) % TAMANHO_FILA;
    f->quantidade--;
}

void mostrarFila(FilaImpressora *f) {
    printf("\nFila atual:\n");
    if (filaVazia(f)) {
        printf("(vazia)\n");
        return;
    }
    
    int pos = f->inicio;
    for (int i = 0; i < f->quantidade; i++) {
        printf("%d. %s\n", i+1, f->documentos[pos]);
        pos = (pos + 1) % TAMANHO_FILA;
    }
}

int main() {
    FilaImpressora impressora;
    inicializarFila(&impressora);
    
    // Adiciona os 4 documentos iniciais
    enfileirar(&impressora, "Relatorio.pdf");
    enfileirar(&impressora, "Planilha.xlsx");
    enfileirar(&impressora, "Apresentacao.pptx");
    enfileirar(&impressora, "Contrato.doc");
    
    int ciclo = 1;
    char novoDoc[50];
    
    while (1) {
        printf("\n=== Ciclo %d ===\n", ciclo++);
        
        // Imprime um documento (remove da fila)
        desenfileirar(&impressora);
        
        // Mostra a fila atual
        mostrarFila(&impressora);
        
        // Adiciona um novo documento
        printf("\nDigite o nome do novo documento (ou 'sair' para terminar): ");
        scanf("%49s", novoDoc);
        
        if (strcmp(novoDoc, "sair") == 0) break;
        
        enfileirar(&impressora, novoDoc);
        mostrarFila(&impressora);
    }
    
    printf("\nSimulacao encerrada.\n");
    return 0;
}