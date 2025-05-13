#include <stdio.h>

int main() {
    int numeros[6];
    int maior, menor;
    int posicao_maior, posicao_menor;

    printf("Digite 6 numeros inteiros:\n");

    // Lê os números do usuário
    for (int i = 0; i < 6; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Inicializa maior e menor com o primeiro elemento
    maior = menor = numeros[0];
    posicao_maior = posicao_menor = 0;

    // Encontra o maior e o menor número
    for (int i = 1; i < 6; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
            posicao_maior = i;
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
            posicao_menor = i;
        }
    }

    // Exibe os resultados
    printf("\nMaior numero: %d (posicao %d)\n", maior, posicao_maior + 1);
    printf("Menor numero: %d (posicao %d)\n", menor, posicao_menor + 1);

    return 0;
}
