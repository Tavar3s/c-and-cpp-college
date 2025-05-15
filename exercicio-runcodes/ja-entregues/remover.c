#include <stdio.h>

int main(void) {
    int num, lista[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &lista[i]);
    }

    scanf("%d", &num);

    for (int i = 0; i < 10; i++) {
        if (lista[i] == num) {
            lista[i] = 0; // Remove o número substituindo por 0
        }
    }

    for (int i = 0; i < 10; i++) {
        if (lista[i] != 0) {
            printf("%d ", lista[i]); 
        }
    }

    return 0;
}