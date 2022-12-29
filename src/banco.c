#include<stdio.h>

int main() {

    int meses, contador = 1;
    float inicial, mensal, final;

    printf("Qual o investimento inicial? ");
    scanf("%f", &inicial);

    printf("Qual o investimento mensal? ");
    scanf("%f", &mensal);

    printf("Por quantos meses voce vai investir? ");
    scanf("%d", &meses);

    final = inicial;

    while (contador <= meses) {
        final = final + (final * 0.005);
        final += mensal;
        printf("\nMes %d = %.2f", contador, final);
        contador++;
    }

    printf("\n\nVoce lucrou %.2f.\n", (final - (mensal * meses + inicial)));

}