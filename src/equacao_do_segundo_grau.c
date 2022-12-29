#include <stdio.h>
#include <math.h>

int delta(int a, int b, int c) {
    return pow(b, 2) - (4 * a * c);
}

int raiz1(int delta, int a, int b) {
    return (-b + sqrt(delta)) / (2 * a);
}

int raiz2(int delta, int a, int b) {
    return (-b - sqrt(delta)) / (2 * a);
}

void equacao2grau(int a, int b, int c) {
    if (a != 0) {
        int d = delta(a, b, c);
        if (d < 0) {
            printf("Essa equacao nao possui raiz real.");
        } else {
            printf("Raiz 1 = %d", raiz1(d, a, b));
            printf("\nRaiz 2 = %d", raiz2(d, a, b));
        }
    } else {
        printf("Essa equacao nao e valida");
    }
}

int main() {
    equacao2grau(0, 8, 16);
}