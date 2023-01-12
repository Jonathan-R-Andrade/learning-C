#include <stdio.h>
#define TAMANHO_DO_VETOR 5

void preencher_vetor(int vetor[]) {
    for (int i = 0; i < TAMANHO_DO_VETOR; i++) {
        printf("Informe o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void copiar_vetor(int origem[], int destino[]) {
    for (int i = 0; i < TAMANHO_DO_VETOR; i++) {
        destino[i] = origem[i];
    }
}

void dobrar_valores(int origem[], int destino[]) {
    for (int i = 0; i < TAMANHO_DO_VETOR; i++) {
        destino[i] = origem[i] * 2;
    }
}

void imprimir_vetor(int vetor[]) {
    for (int i = 0; i < TAMANHO_DO_VETOR; i++) {
        if (i > 0) printf(" ");
        printf("%d", vetor[i]);
    }
    printf("\n");
}

int main() {
    int original[TAMANHO_DO_VETOR];
    int copia[TAMANHO_DO_VETOR];
    int dobrado[TAMANHO_DO_VETOR];

    preencher_vetor(original);
    copiar_vetor(original, copia);
    dobrar_valores(original, dobrado);

    printf("\nVetor original:\n");
    printf("Valores: ");
    imprimir_vetor(original);
    printf("Ponteiro = %p\n\n", original);

    printf("Vetor copiado:\n");
    printf("Valores: ");
    imprimir_vetor(copia);
    printf("Ponteiro = %p\n\n", copia);

    printf("Vetor dobrado:\n");
    printf("Valores: ");
    imprimir_vetor(dobrado);
    printf("Ponteiro = %p\n", dobrado);
}
