#include <stdio.h>

int main() {
    int array[10];
    int soma = 0;

    printf("Digite 10 numeros inteiros:\n");

    // Lê os valores inseridos pelo usuário
    for (int i = 0; i < 10; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &array[i]);
        soma += array[i]; // Soma cada elemento ao total
    }

    // Exibe a soma total
    printf("\nA soma total dos elementos e: %d\n", soma);

    return 0;
}