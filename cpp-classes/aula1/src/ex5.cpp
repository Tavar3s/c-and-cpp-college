/*
    Código para calcular e exibir os valores de vx e vy em um movimento senoidal
    com base na equação fornecida, além de gerar uma tabela de valores.
*/

#include <iostream>
#include <cmath>
#include <iomanip> // Para formatar a saída

// Definições de constantes
#define MEIO_COMPRIMENTO 5
#define CONSTANTE_C 1
#define VELOCIDADE_INICIAL 15

// Funções para calcular os valores de vx e vy
double retorna_valor_vx(double x) {
    return VELOCIDADE_INICIAL * pow(1 + pow(CONSTANTE_C * M_PI / MEIO_COMPRIMENTO, 2) * pow(cos(M_PI * x / MEIO_COMPRIMENTO), 2), -1.0 / 2.0);
}

double retorna_valor_vy(double x) {
    return VELOCIDADE_INICIAL * pow(1 + pow(CONSTANTE_C * M_PI / MEIO_COMPRIMENTO, 2) * pow(cos(M_PI * x / MEIO_COMPRIMENTO), 2), -1.0 / 2.0) * cos(M_PI * x / MEIO_COMPRIMENTO) * CONSTANTE_C * M_PI / MEIO_COMPRIMENTO;
}

int main() {
    double x;

    // Entrada do usuário
    
    std::cout << "Digite um valor para x: ";
    std::cin >> x;

    // Cálculo e exibição dos valores de vx e vy para o valor inserido
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Para x = " << x << ":\n";
    std::cout << "vx = " << retorna_valor_vx(x) << "\n";
    std::cout << "vy = " << retorna_valor_vy(x) << "\n";

    // Tabela de valores
    std::cout << "\nTabela de valores:\n";
    std::cout << "x\t\tvx\t\tvy\n";
    std::cout << "-----------------------------------\n";

    double valores_x[] = {0, MEIO_COMPRIMENTO / 2.0, MEIO_COMPRIMENTO, 3 * MEIO_COMPRIMENTO / 2.0, 2 * MEIO_COMPRIMENTO};
    for (double xi : valores_x) {
        std::cout << xi << "\t\t" << retorna_valor_vx(xi) << "\t\t" << retorna_valor_vy(xi) << "\n";
    }

    return 0;
}