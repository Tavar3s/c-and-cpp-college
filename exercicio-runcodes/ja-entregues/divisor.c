#include <stdio.h>

int main(void) {
    int num, contador = 0;

    scanf("%i", &num);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            contador++;
            printf("%i ", i);
        }
    }

    if (contador == 2) {
        printf("\nO numero %i eh primo", num);
    }

    return 0;
}