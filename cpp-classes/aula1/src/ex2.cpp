/*
    Simples programa C++ que calcula a distância entre dois pontos
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x1, y1, x2, y2;

    // Solicita as coordenadas dos pontos ao usuário
    cout << "Calculadora de distância entre dois pontos" << endl;
    cout << "Digite as coordenadas do primeiro ponto (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Digite as coordenadas do segundo ponto (x2 y2): ";
    cin >> x2 >> y2;

    // Calcula a distância usando a fórmula da distância euclidiana
    float distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Exibe o resultado
    cout << "A distância entre os pontos (" << x1 << ", " << y1 << ") e (" 
         << x2 << ", " << y2 << ") é: " << distancia << endl;

    return 0;
}