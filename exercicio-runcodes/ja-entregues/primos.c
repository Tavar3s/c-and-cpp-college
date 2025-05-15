#include <stdio.h>

int primo(int n) {
    if (n < 2) return 0; // Números menores que 2 não são primos
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // Se n é divisível por i, não é primo
    }
    return 1; // Se não encontrou divisores, n é primo
}

int main() {
    int num1;

    scanf("%d", &num1);

    if (primo(num1)) {
        printf("O numero %d eh primo\n", num1);
    } else {
        printf("O numero %d nao eh primo\n", num1);
    }
}