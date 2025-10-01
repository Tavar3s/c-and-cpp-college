#include <iostream>
#include <cmath> // Para função pow

// Definições de constantes
#define MEIO_COMPRIMENTO 5
#define CONSTANTE_C 1
#define VELOCIDADE_INICIAL 15

long long fatorial(int n) {
    if (n == 0 || n == 1) return 1;
        long long resultado = 1;
    return n * fatorial(n - 1);
}

double cosseno(double x) {
    double soma = 0.0;
    for (int i = 0; i <= 10; i++) {
        soma += (pow(-1, i) * pow(x, 2 * i)) / fatorial(2 * i);
    }
    return soma;
}

// Funções para calcular os valores de vx e vy
long double retorna_valor_vx(double x) {
    return VELOCIDADE_INICIAL * pow(1 + pow(CONSTANTE_C * M_PI / MEIO_COMPRIMENTO, 2) * pow(cosseno(M_PI * x / MEIO_COMPRIMENTO), 2), -1.0 / 2.0);
}

long double retorna_valor_vy(double x) {
    return VELOCIDADE_INICIAL * pow(1 + pow(CONSTANTE_C * M_PI / MEIO_COMPRIMENTO, 2) * pow(cosseno(M_PI * x / MEIO_COMPRIMENTO), 2), -1.0 / 2.0) * cosseno(M_PI * x / MEIO_COMPRIMENTO) * CONSTANTE_C * M_PI / MEIO_COMPRIMENTO;
}

int main() {
    double valores_x[] = {0, MEIO_COMPRIMENTO / 2.0, MEIO_COMPRIMENTO, 3 * MEIO_COMPRIMENTO / 2.0, 2 * MEIO_COMPRIMENTO};
    for (double xi : valores_x) {
        std::cout << xi << "\t\t" << retorna_valor_vx(xi) << "\t\t" << retorna_valor_vy(xi) << "\n";
    }
}