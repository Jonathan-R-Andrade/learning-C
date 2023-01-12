#include <stdio.h>
#include <stdlib.h>

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

int calcular_fibonacci(int **sequencia_fibonacci, int *termos_totais, int posicao) {
    if (posicao > *termos_totais) {
        int novo_tamanho_memoria = posicao * sizeof(int);
        int *nova_sequencia_fibonacci = (int *)realloc(*sequencia_fibonacci, novo_tamanho_memoria);
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
    int posicao = 0, termos_totais = 2;
    int *sequencia_fibonacci = (int *)malloc(termos_totais * sizeof(int));
    if (sequencia_fibonacci == NULL) {
        puts("Erro ao alocar memória!");
        return 1;
    }
    sequencia_fibonacci[0] = 0;
    sequencia_fibonacci[1] = 1;

    puts("Sequência de Fibonacci");
    puts("Digite a posição do termo que você quer ver ou 0 para encerrar.\n");

    do {
        posicao = -1;
        printf("Digite a posição do termo: ");
        scanf("%d", &posicao);
        limpar_entrada_padrao();

        if (posicao < 0) {
            puts("Posição incorreta.\n");
            posicao = 1;
            continue;
        } else if (posicao == 0) {
            break;
        }

        int valor = calcular_fibonacci(&sequencia_fibonacci, &termos_totais, posicao);
        printf("O %dº termo na sequência de Fibonacci é %d\n\n", posicao, valor);
    } while (posicao > 0);

    free(sequencia_fibonacci);
    puts("\nPrograma encerrado.");
    return 0;
}
