#include <stdio.h>

int main(void) {
    float lista[15], count = 0;

    for (int i = 0; i < 15; i++) {
        scanf("%f", &lista[i]);
    }

    for (int i = 0; i < 15; i++) {
        if (lista[i] > 0) {
            count++;
        }
    }

    printf("%.0f valores positivos", count);

    return 0;
}