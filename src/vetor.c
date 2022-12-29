#include <stdio.h>
#define DIM 5

void receber(int original[]) {
    int count = 1;
    for (count = 0; count < DIM; count++) {
        printf("Informe o valor %d: ", count+1);
        scanf("%d", &original[count]);
    }
}

void copiar(int copiado[], int original[]) {
    for (int coluna = 0; coluna < DIM; coluna++) {
        copiado[coluna] = original[coluna];
    }
}

void dobrar(int dobrar[], int original[]) {
    for (int coluna = 0; coluna < DIM; coluna++) {
        dobrar[coluna] = original[coluna] * 2;
    }
}

void exibir(int vetor[]) {
    for (int coluna = 0; coluna < DIM; coluna++) {
        printf("%3d", vetor[coluna]);
    }
    printf("\n");
}

int main() {

    int original[DIM];
    int copia[DIM];
    int dobrado[DIM];

    receber(original);
    copiar(copia, original);
    dobrar(dobrado, original);

    printf("\nVetor original: ");
    exibir(original);
    printf("Vetor copiado : ");
    exibir(copia);
    printf("Vetor dobrado : ");
    exibir(dobrado);
}