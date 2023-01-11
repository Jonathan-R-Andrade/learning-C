#include <stdio.h>

unsigned long long calcular_fatorial(int numero) {
    unsigned long long fatorial = numero;

    for (int i = numero; i > 2; i -= 2) {
        fatorial = fatorial * (i - 1) * (i - 2);
    }

    return fatorial;
}

int main() {
    int numero = 0;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 1) {
        puts("O número deve ser um inteiro positivo.");
        return 1;
    }

    unsigned long long fatorial = calcular_fatorial(numero);

    printf("%d! = %llu\n", numero, fatorial);
    return 0;
}
