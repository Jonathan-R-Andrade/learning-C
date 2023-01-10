#include <stdio.h>

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

int main() {
    char *nome_do_arquivo = "media.txt";
    int total = 0;
    double numero, media = 0.0;
    FILE *arquivo = fopen(nome_do_arquivo, "w");

    if (arquivo == NULL)
        printf("Erro ao abrir/criar o arquivo \"%s\"!\n", nome_do_arquivo);
    else {
        puts(
            "Informe números decimais.\n"
            "Digite 0 para parar.\n");

        do {
            numero = 0;
            printf("Número: ");
            scanf(" %lf", &numero);
            limpar_entrada_padrao();
            media += numero;
            if (numero != 0) {
                total++;
                fprintf(arquivo, "%g\n", numero);
            }
        } while (numero != 0);

        media /= total;
        fprintf(arquivo, "Média = %g", media);
    }

    printf("\nArquivo \"%s\" salvo.\n", nome_do_arquivo);
    fclose(arquivo);
    return 0;
}
