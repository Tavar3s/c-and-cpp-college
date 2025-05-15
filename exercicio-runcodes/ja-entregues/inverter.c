#include <stdio.h>

int main(void) {
    int original[8], inversa[8];

    for (int i = 0; i < 8; i++) {
        scanf("%d", &original[i]);
    }

    for (int i = 0; i < 8; i++) {
        inversa[i] = original[7 - i];
    }

    for (int i = 0; i < 8; i++) {
        printf("%d ", original[i]);
    }
    
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", inversa[i]);
    }

    return 0;
}