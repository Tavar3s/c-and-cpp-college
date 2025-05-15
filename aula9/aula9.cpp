#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, j;
    srand(time(NULL));

    // Define valores para i(linhas) e j(colunas)
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &i);
    scanf("%d", &j);

    // Aloca a matriz desejada na HEAP
    int** matriz = NULL;
    matriz = (int**)malloc(i * sizeof(int*));
    for (int k = 0; k < i; k++) {
        matriz[k] = (int*)malloc(j * sizeof(int));
    }

    // Atribui valores aleatórios à matriz e imprime 
    for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
            matriz[k][l] = rand() % 100;
            printf("%d ", matriz[k][l]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    for (int k = 0; k < i; k++) {
        free(matriz[k]);
        matriz[k] = NULL;
    }
    free(matriz);
    matriz = NULL;

    return 0;
}

