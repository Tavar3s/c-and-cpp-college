#include <stdio.h>

int quadrada(int x) {
    return x * x;
}

int main() {
    int num1, num2, num3;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    printf("Quadrado de %d: %d\n", num1, quadrada(num1));
    printf("Quadrado de %d: %d\n", num2, quadrada(num2));
    printf("Quadrado de %d: %d\n", num3, quadrada(num3));

    return 0;
}