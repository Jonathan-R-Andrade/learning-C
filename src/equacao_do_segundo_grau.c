#include <math.h>
#include <stdio.h>

int calcular_delta(int a, int b, int c) {
    return pow(b, 2) - (4 * a * c);
}

int calcular_raiz_1(int delta, int a, int b) {
    return (-b + sqrt(delta)) / (2 * a);
}

int calcular_raiz_2(int delta, int a, int b) {
    return (-b - sqrt(delta)) / (2 * a);
}

void calcular_equacao_2_grau(int a, int b, int c) {
    if (a != 0) {
        int delta = calcular_delta(a, b, c);
        if (delta < 0) {
            printf("Essa equação não possui raiz real.\n");
        } else {
            printf("Raiz 1 = %d\n", calcular_raiz_1(delta, a, b));
            printf("Raiz 2 = %d\n", calcular_raiz_2(delta, a, b));
        }
    } else {
        printf("Essa equação não é válida.\n");
    }
}

int main() {
    calcular_equacao_2_grau(0, 8, 16);
    calcular_equacao_2_grau(5, 2, 20);
    calcular_equacao_2_grau(3, 15, 66);
}
