#include <iostream>
#include <cmath>

long double soma(int n) {
    long double s = 0.0;
    for (int i = 0; i < n; i++) {
        s = s + (pow(2, i + 1) / (n - i));
    }
    return s;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << soma(n) << std::endl;
    return 0;
}