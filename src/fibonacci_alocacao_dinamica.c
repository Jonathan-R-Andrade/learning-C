#include <stdio.h>
#include <stdlib.h>

// Posição do último termo da sequência de Fibonacci que é possível calcular com 64 bits
#define ULTIMO_TERMO 94

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

unsigned long long int calcular_fibonacci(unsigned long long int **sequencia_fibonacci,
                                          int *termos_totais, int posicao) {
    if (posicao > *termos_totais) {
        int novo_tamanho_memoria = posicao * sizeof(unsigned long long int);
        unsigned long long int *nova_sequencia_fibonacci =
            (unsigned long long int *)realloc(*sequencia_fibonacci, novo_tamanho_memoria);
        if (nova_sequencia_fibonacci == NULL) {
            puts("Erro ao realocar memória!");
            free(*sequencia_fibonacci);
            exit(1);
        }
        *sequencia_fibonacci = nova_sequencia_fibonacci;

        for (int i = *termos_totais; i < posicao; i++) {
            (*sequencia_fibonacci)[i] =
                (*sequencia_fibonacci)[i - 1] + (*sequencia_fibonacci)[i - 2];
        }

        *termos_totais = posicao;
    }
    return (*sequencia_fibonacci)[posicao - 1];
}

int main() {
    int termos_totais = 2;
    int tamanho_memoria = termos_totais * sizeof(unsigned long long int);
    unsigned long long int *sequencia_fibonacci;

    sequencia_fibonacci = (unsigned long long int *)malloc(tamanho_memoria);
    if (sequencia_fibonacci == NULL) {
        puts("Erro ao alocar memória!");
        return 1;
    }
    sequencia_fibonacci[0] = 0;
    sequencia_fibonacci[1] = 1;

    puts("Sequência de Fibonacci");
    printf(
        "Digite a posição do termo que você quer ver de 1 a %d "
        "ou 0 para encerrar.\n\n",
        ULTIMO_TERMO);

    int posicao;
    while (posicao != 0) {
        posicao = -1;
        printf("Digite a posição do termo: ");
        scanf("%d", &posicao);
        limpar_entrada_padrao();

        if (posicao < 0 || posicao > ULTIMO_TERMO) {
            puts("Posição incorreta.\n");
            continue;
        } else if (posicao > 0) {
            unsigned long long int valor =
                calcular_fibonacci(&sequencia_fibonacci, &termos_totais, posicao);
            printf("O %dº termo na sequência de Fibonacci é %llu\n\n", posicao, valor);
        }
    }

    free(sequencia_fibonacci);
    puts("\nPrograma encerrado.");
    return 0;
}
