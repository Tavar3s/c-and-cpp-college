/*
    O programa calcula o valor de alpha com base na fórmula:
    alpha = (e^beta / gamma) * sin(n)
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double alpha, beta, gamma, n;

    // Solicita os valores de beta, gamma e n ao usuário
    cout << "Digite o valores de beta, gamma e n: ";
    cin >> beta >> gamma >> n;

    // Calcula o valor de alpha usando a fórmula fornecida
    alpha = (pow(M_E, beta) / gamma) * sin(n);

    // Exibe o resultado formatado com duas casas decimais
    cout << fixed << setprecision(2);
    cout << "O valor de alpha é: " << alpha << endl;

    return 0;
}