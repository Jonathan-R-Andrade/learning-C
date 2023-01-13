#include <math.h>
#include <stdio.h>

double calcular_delta(int a, int b, int c) {
    return pow(b, 2) - (4 * a * c);
}

double calcular_raiz_1(int delta, int a, int b) {
    return (-b + sqrt(delta)) / (2 * a);
}

double calcular_raiz_2(int delta, int a, int b) {
    return (-b - sqrt(delta)) / (2 * a);
}

void calcular_equacao_2_grau(int a, int b, int c) {
    if (a != 0) {
        double delta = calcular_delta(a, b, c);
        if (delta < 0) {
            printf("Essa equação não possui solução real.\n");
        } else if (delta == 0) {
            printf("x = %g\n", calcular_raiz_1(delta, a, b));
        } else {
            printf("x1 = %g\n", calcular_raiz_1(delta, a, b));
            printf("x2 = %g\n", calcular_raiz_2(delta, a, b));
        }
    } else {
        printf("Essa equação não é do 2º grau. O coeficiente \"a\" não pode ser 0.\n");
    }
}

int main() {
    puts("8x + 16 = 0");
    calcular_equacao_2_grau(0, 8, 16);
    puts("");

    puts("5x² + 2x + 20 = 0");
    calcular_equacao_2_grau(5, 2, 20);
    puts("");

    puts("x² - 12 = 0");
    calcular_equacao_2_grau(1, 0, -12);
    puts("");

    puts("5x² + 10x + 5 = 0");
    calcular_equacao_2_grau(5, 10, 5);
    puts("");

    puts("x² + 8x = 0");
    calcular_equacao_2_grau(1, 8, 0);
    puts("");

    puts("2x² - 4 = 0");
    calcular_equacao_2_grau(2, 0, -4);
    puts("");

    puts("9x² = 0");
    calcular_equacao_2_grau(9, 0, 0);
}
