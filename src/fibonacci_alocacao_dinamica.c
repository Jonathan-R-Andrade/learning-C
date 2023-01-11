#include <stdio.h>
#include <stdlib.h>

void exibe(int *ptr, int termo, int *size) {
    if (termo > *size) {
        int v = (*size * sizeof(int));
        int n = ((termo - *size) * sizeof(int));
        printf("Velho %d\nNovo %d\n\n", v, n);
        ptr = realloc(ptr, v + n);
        int i;
        for (i = *size; i < termo; i++) {
            ptr[*size] = ptr[*size - 1] + ptr[*size - 2];
            *size += 1;
        }
        printf("Termo %d = %d\n\n", termo, ptr[termo - 1]);
    } else {
        printf("Termo %d = %d\n\n", termo, ptr[termo - 1]);
    }
}

int calcular_fibonacci(int *sequencia_fibonacci, int *termos_totais, int termo) {
    if (termo > *termos_totais) {
        int novo_tamanho_memoria = termo * sizeof(int);
        sequencia_fibonacci = realloc(sequencia_fibonacci, novo_tamanho_memoria);
        
        for (int i = *termos_totais; i < termo; i++) {
            sequencia_fibonacci[i] = sequencia_fibonacci[i - 1] + sequencia_fibonacci[i - 2];
        }
        *termos_totais = termo;
    }
    return sequencia_fibonacci[termo - 1];
}

int main(void) {
    int posicao = 0, termos_totais = 2;
    int *sequencia_fibonacci = malloc(termos_totais * sizeof(int));
    sequencia_fibonacci[0] = 0;
    sequencia_fibonacci[1] = 1;

    puts("Sequência de Fibonacci");
    puts("Digite a posição do termo que você quer ver ou 0 para encerrar.\n");

    do {
        printf("Digite a posição do termo: ");
        scanf("%d", &posicao);
        if (posicao <= 0) break;

        int valor = calcular_fibonacci(sequencia_fibonacci, &termos_totais, posicao);
        printf("O %dº termo na sequência de Fibonacci é %d\n\n", posicao, valor);
        printf("*** %d\n\n", termos_totais);
    } while (posicao > 0);

    puts("\nPrograma encerrado.");
    return 0;
}
