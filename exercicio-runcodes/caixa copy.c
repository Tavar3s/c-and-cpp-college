#include <stdio.h>



void caixa_eletronico(int saque, int valor[], int notas[]) {
    int count = 0;

    while (saque > 0) {
        do {
            saque -= valor[count];
            notas[count]++;
        } while (saque % valor[count+1] != 0 && count < 6);
        count++;
    }

    for (int k = 0; k < 4; k++) {
        if (notas[0] >= 5) {
        notas[0] -= 5;
        notas[1] += 1;
        }

        if (notas[1] >= 2) {
            notas[1] -= 2;
            notas[2] += 1;
        }

        if (notas[2] >= 2) {
            notas[2] -= 2;
            notas[3] += 1;
        }

        if (notas[3] >= 2 && notas[2] >= 1) {
            notas[2] -= 1;
            notas[3] -= 2;
            notas[4] += 1;
        }

        if (notas[4] >= 2) {
            notas[4] -= 2;
            notas[5] += 1;
        }
    }

    for (int i = 5; i >= 0; i--) {
        printf("Notas de %d: %d\n", valor[i], notas[i]);
    }
        
};

int main(void) {
    int saque;
    int valor[6] = {2, 5, 10, 20, 50, 100};
    int notas[6] = {0, 0, 0, 0, 0, 0};

    scanf("%d", &saque);

    if (saque < 10) {
        return 0;
    }

    caixa_eletronico((int)saque, valor, notas);

    return 0;
}