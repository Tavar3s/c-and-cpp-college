#include <stdio.h>

double raiz_quadrada(double num) {
    double x = num, y = 1.0;
    double precisao = 0.000001; // Precisão desejada

    while (x - y > precisao) {
        x = (x + y) / 2;
        y = num / x;
    }
    return x;
}

int main(void) {
    double numero;
    scanf("%lf", &numero);
    printf("%.6lf\n", raiz_quadrada(numero));
    return 0;
}
