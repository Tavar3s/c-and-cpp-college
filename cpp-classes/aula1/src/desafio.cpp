/*
    Código para calcular o vetor força entre dois pontos A e B no espaço tridimensional.
    O vetor força é calculado como um vetor unitário na direção de A para B,
*/

#include <iostream>
#include <cmath>

using namespace std;

// Função para calcular o vetor unitário
void retorna_vetor_unitario(float vetor[3], float vetorUnitario[3]) {
    float modulo = 0;

    // Calcula o módulo do vetor
    for (int i = 0; i < 3; i++) {
        modulo += vetor[i] * vetor[i];
    }

    modulo = sqrt(modulo);

    // Calcula o vetor unitário
    for (int i = 0; i < 3; i++) {
        vetorUnitario[i] = vetor[i] / modulo;
    }
}

int main() {
    float vetorA[3], vetorB[3], vetorPosicao[3], vetorUnitario[3];
    double moduloForca;

    // Entrada dos vetores A e B
    cout << "Digite os valores do vetor A (3 valores): ";
    for (int i = 0; i < 3; i++) {
        cin >> vetorA[i];
    }
    cout << "Digite os valores do vetor B (3 valores): ";
    for (int i = 0; i < 3; i++) {
        cin >> vetorB[i];
    }

    // Calcula e exibe o vetor posição
    for (int i = 0; i < 3; i++) {
        vetorPosicao[i] = vetorA[i] - vetorB[i];
    }

    cout << "Vetor posição: ";
    for (int i = 0; i < 3; i++) {
        cout << vetorPosicao[i];
        if (i < 2) cout << ", ";
    }
    cout << endl;

    cout << "-------------------" << endl;

    // Entrada do módulo da força
    cout << "Digite o módulo da força: ";
    cin >> moduloForca;

    // Calcula o vetor unitário
    retorna_vetor_unitario(vetorPosicao, vetorUnitario);

    // Calcula e exibe o vetor força
    cout << "Vetor força: ";
    for (int i = 0; i < 3; i++) {
        char versores[3] = {'i', 'j', 'k'};
        cout << vetorUnitario[i] * moduloForca << versores[i];
        if (i < 2) cout << ", ";
    }

    return 0;
}