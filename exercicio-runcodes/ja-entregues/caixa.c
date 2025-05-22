#include <stdio.h>



void caixa_eletronico(int saque, int valor[], int notas[]) {
    int num = saque;
    while (num > 2) {
        for (int i = 0; i < 6; i++) {
            if (num >= valor[i]) {
                notas[i] = num / valor[i];
                num = num - (notas[i] * valor[i]);
                printf("Notas de %d: %d\n", valor[i], notas[i]);
            } else {
                printf("Notas de %d: 0\n", valor[i]);
            }
        }
    }
};

int main(void) {
    int saque;
    int valor[6] = {100, 50, 20, 10, 5, 2};
    int notas[6] = {0, 0, 0, 0, 0, 0};

    scanf("%d", &saque);

    if (saque < 10) {
        return 0;
    }

    caixa_eletronico(saque, valor, notas);

    return 0;
}