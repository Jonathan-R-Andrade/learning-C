#include <stdio.h>

int main() {

    int operacao, n1, n2;

    do {

        printf("Escolha uma operacao:\n"
                "1. Para soma.\n"
                "2. Para subtracao.\n"
                "3. Para multiplicacao.\n"
                "4. Para divicao.\n");

        scanf("%d", &operacao);

        printf("Informe o primeiro numero: ");
        scanf("%d", &n1);

        printf("Informe o segundo numero: ");
        scanf("%d", &n2);

        switch (operacao) {
            case 1:
                printf("%d + %d = %d", n1, n2, (n1 + n2));
                break;
            case 2:
                printf("%d - %d = %d", n1, n2, (n1 - n2));
                break;
            case 3:
                printf("%d * %d = %d", n1, n2, (n1 * n2));
                break;
            case 4:
                printf("%d / %d = %d", n1, n2, (n1 / n2));
                break;
        }

        printf("\nVoce deseja fazer outra conta:\n"
                "0. Nao.\n"
                "1. Sim.\n");
        scanf("%d", &operacao);

        if (operacao == 1)
            system("clear || cls");

    } while (operacao);
}