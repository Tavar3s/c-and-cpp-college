#include <iostream>

long double soma(int n, float* x) {
    long double  soma = 0;
    for (int i = 0; i < n; i++) {
        soma += x[i];
    }
    return soma;
}

long double soma_produto(int n, float* y, float* x) {
    long double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (x[i]*y[i]);
    }
    return soma;
}

long double soma_quadrado(int n, float* x) {
    long double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += x[i]*x[i];
    }
    return soma;
}

long double valor_a(int n, float* x, float* y) {
    return (n * soma_produto(n, y, x) - soma(n, x) * soma(n, y)) / (n * soma_quadrado(n, x) - soma(n, x) * soma(n, x));
}

long double valor_b(int n, float* x, float* y) {
    return (soma(n, y) * soma_quadrado(n, x) - soma(n, x) * soma_produto(n, y, x))/(n * soma_quadrado(n, x) - soma(n, x) * soma(n, x));
}

using namespace std;

int main() {
    int n = 6;
    float x[n] = {4, 6, 7, 5, 8, 10};
    float y[n] = {15, 18, 19, 20, 21, 23};
    long double a, b;
    
    a = valor_a(n, x, y);
    b = valor_b(n, x, y);
    cout.precision(3);
    cout << fixed << a << " " << b << endl;
    return 0;
}