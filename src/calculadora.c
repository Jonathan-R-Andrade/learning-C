#include <stdio.h>
#include <stdlib.h>

void limpar_entrada_padrao() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}

void obter_numeros(double *numero_1, double *numero_2) {
    printf("\nInforme o primeiro número: ");
    scanf(" %lf", numero_1);
    limpar_entrada_padrao();

    printf("Informe o segundo número: ");
    scanf(" %lf", numero_2);
    limpar_entrada_padrao();
}

int main() {
    char operacao;
    double numero_1, numero_2;

    do {
        printf(
            "Escolha uma operação:\n"
            "0. Sair.\n"
            "+. Somar.\n"
            "-. Subtrair.\n"
            "*. Multiplicar.\n"
            "/. Dividir.\n\n");

        printf("Operação: ");
        scanf(" %c", &operacao);
        limpar_entrada_padrao();

        if (operacao == '0') break;

        switch (operacao) {
            case '+':
                obter_numeros(&numero_1, &numero_2);
                printf("%g + %g = %g\n\n", numero_1, numero_2, (numero_1 + numero_2));
                break;
            case '-':
                obter_numeros(&numero_1, &numero_2);
                printf("%g - %g = %g\n\n", numero_1, numero_2, (numero_1 - numero_2));
                break;
            case '*':
                obter_numeros(&numero_1, &numero_2);
                printf("%g * %g = %g\n\n", numero_1, numero_2, (numero_1 * numero_2));
                break;
            case '/':
                obter_numeros(&numero_1, &numero_2);
                printf("%g / %g = %g\n\n", numero_1, numero_2, (numero_1 / numero_2));
                break;
            default:
                puts("Operação inválida.\n");
        }
    } while (operacao != '0');

    puts("\nPrograma encerrado.");
    return 0;
}
