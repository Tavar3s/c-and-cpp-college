/*
    Simples programa C++ que mede aceleração, velocidade e posição de um carro em movimento
    com base no tempo fornecido pelo usuário.
*/

#include <iostream>
#include <cmath>

// Funções para medir aceleração, velocidade e posição
double medir_aceleracao(double tempo) {
    return 1.8 * tempo + 0.6;
}

double medir_velocidade(double tempo) {
    return 0.9 * pow(tempo, 2) + 0.6 * tempo;
}

double medir_posicao(double tempo) {
    return 0.3 * pow(tempo, 3) + 0.3 * pow(tempo, 2);
}

int main() {
    double tempo;

    // Solicita ao usuário o tempo em segundos
    std::cout << "Digite o tempo (em segundos): ";
    std::cin >> tempo;

    // Usa as funções para calcular aceleração, velocidade e posição
    double aceleracao = medir_aceleracao(tempo);
    double velocidade = medir_velocidade(tempo);
    double posicao = medir_posicao(tempo);

    // Exibe os resultados
    std::cout << "Aceleração: " << aceleracao << " m/s²" << std::endl;
    std::cout << "Velocidade: " << velocidade << " m/s" << std::endl;
    std::cout << "Posição: " << posicao << " m" << std::endl;

    return 0;
}