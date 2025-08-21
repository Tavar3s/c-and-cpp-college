/*
    Programa que recebe um vetor (x, y) e um ângulo em graus,
    e rotaciona o vetor pelo ângulo especificado. Uso de números complexos para a rotação.
*/

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    float angulo_graus, angulo_radianos, x, y;

    // Solicita as coordenadas do vetor e o ângulo
    cout << "Digite as coordenadas do vetor (x y): ";
    cin >> x >> y;
    cout << "Digite o ângulo em graus: ";
    cin >> angulo_graus;

    // Converte o ângulo de graus para radianos
    angulo_radianos = angulo_graus * (M_PI / 180.0);

    // Cria o vetor como um número complexo e aplica a rotação
    complex<float> vetor(x, y);
    complex<float> vetor_rotator(cos(angulo_radianos), sin(angulo_radianos));
    complex<float> vetor_rotacionado = vetor * vetor_rotator;

    // Exibe o vetor rotacionado
    cout << "Vetor rotacionado: (" << real(vetor_rotacionado) << ", " << imag(vetor_rotacionado) << ")" << endl;

    return 0;
}