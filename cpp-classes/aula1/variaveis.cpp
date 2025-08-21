#include <iostream>

using namespace std;

int main() {
    int x1, x2, x3;
    cout << "Digite três números inteiros: ";
    cin >> x1 >> x2 >> x3;
    cout << "Valores digitados:" << x1 << ", " << x2 << ", " << x3 << endl;
    cout << "Soma: " << (x1 + x2 + x3) << endl;
    cout << "Produto: " << (x1 * x2 * x3) << endl;
    cout << "Média: " << (x1 + x2 + x3) / 3.0 << endl;

    return 0;
}