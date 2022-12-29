#include<stdio.h>

int main() {
    int n, fatorial, contador;
    printf("Informe um numero: ");
    scanf("%d", &n);
    fatorial = n;
    contador = n;
    while (contador > 2) {
        fatorial = fatorial * (contador - 1) * (contador - 2);
        contador -= 2;
    }
    printf("%d! = %d\n", n, fatorial);
}