#include <iostream>

using namespace std;

double integralt(float a, float b, float h) {
    double integral = 0.0;
    for (float x = a; x < b; x += h) {
        cout << x << endl;
        integral += (1 / (1 + x * x) + 1 / (1 + (x+h)*(x+h)))/2 * h;
    }
    return integral;
}

int main() {
    float a, b, h;
    cin >> a >> b >> h;
    cout.precision(6);
    double valor_integral = 4 * integralt(a, b, h);
    cout << fixed << valor_integral << endl;
    return 0;
}