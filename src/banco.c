#include <stdio.h>

int main() {
    int meses = 0;
    double juros = 0, valor_inicial = 0, valor_mensal = 0, valor_final;

    printf("Qual é o investimento inicial? ");
    scanf(" %lf", &valor_inicial);

    printf("Qual é o investimento mensal? ");
    scanf(" %lf", &valor_mensal);

    printf("Por quantos meses você vai investir? ");
    scanf(" %d", &meses);

    printf("Qual é a taxa de juros mensal (Exemplo 0.5)? ");
    scanf(" %lf", &juros);

    valor_final = valor_inicial;
    juros = (juros / 100) + 1;

    for (int mes = 1; mes <= meses; mes++) {
        valor_final *= juros;
        valor_final += valor_mensal;
        printf("\nMês %d = %.2f", mes, valor_final);
    }

    double total_investido = valor_inicial + (valor_mensal * meses);
    double lucro = valor_final - total_investido;

    printf("\n\nValor total investido %.2lf\n", total_investido);
    printf("Valor total final %.2lf\n", valor_final);
    printf("Você lucrou %.2lf\n", lucro);
}
