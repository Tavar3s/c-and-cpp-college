#include <stdio.h>

int main(void) {
    int max, min, lista[15];

    for (int i = 0; i < 15; i++) {
       scanf("%d", &lista[i]);
    }

    for (int i = 0; i < 15; i++) {
        if (i == 0) {
            max = lista[i];
            min = lista[i];
        } else {
            if (lista[i] > max) {
                max = lista[i];
            }
            if (lista[i] < min) {
                min = lista[i];
            }
        }
    }

    printf("Valor minimo: %d\n", min);
    printf("Valor maximo: %d\n", max);

    return 0;
}