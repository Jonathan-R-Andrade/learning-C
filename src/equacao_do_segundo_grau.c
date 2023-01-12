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
        int d = calcular_delta(a, b, c);
        if (d < 0) {
            printf("Essa equação não possui raiz real.");
        } else {
            printf("Raiz 1 = %d", calcular_raiz_1(d, a, b));
            printf("\nRaiz 2 = %d", calcular_raiz_2(d, a, b));
        }
    } else {
        printf("Essa equação não é válida.");
    }
}

int main() {
    calcular_equacao_2_grau(0, 8, 16);
}
