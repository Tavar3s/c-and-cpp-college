#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int** matriz = NULL;
    int ordem;

    scanf("%d", &ordem);

    matriz = (int**)malloc(ordem * sizeof(int*));
    for (int i = 0; i < ordem; i++) {
        matriz[i] = (int*)malloc(ordem * sizeof(int));
    }

    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }

    return 0;
}