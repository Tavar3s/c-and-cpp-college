#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Alocação de memória para um vetor de decimais e rand definido
    srand(time(NULL));
    float** matriz_temperaturas = NULL;
    float** temperaturas_medias = NULL;
    char** estado_temperaturas = NULL;

    // Alocação de memória para as matrizes
    matriz_temperaturas = (float**) malloc(10 * sizeof(float*));
    for (int i = 0; i < 10; i++) {
        matriz_temperaturas[i] = (float*) malloc(10 * sizeof(float));
    }

    temperaturas_medias = (float**) malloc(5 * sizeof(float*));
    for (int i = 0; i < 5; i++) {
        temperaturas_medias[i] = (float*) malloc(5 * sizeof(float));
    }

    estado_temperaturas = (char**) malloc(5 * sizeof(char*));
    for (int i = 0; i < 10; i++) {
        estado_temperaturas[i] = (char*) malloc(5 * sizeof(char));
    }

    // Preenchendo a matriz de temperaturas com valores aleatórios
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz_temperaturas[i][j] = (float)(rand() % 100);
        }
    }

    // Calculando a média das temperaturas em janelas 2x2
    for (int k=0; k < 5; k++) {
        for (int l = 0; l < 5; l++) {
            temperaturas_medias[k][l] = 0;
            for (int i = k * 2; i < (k + 1) * 2; i++) {
                for (int j = l * 2; j < (l + 1) * 2; j++) {
                    temperaturas_medias[k][l] += matriz_temperaturas[i][j];
                }
            }
            temperaturas_medias[k][l] /= 4.0;
        }
    }

    // Classificando as temperaturas médias
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (temperaturas_medias[i][j] <= 65) {
                estado_temperaturas[i][j] = 'P';
            } else if (temperaturas_medias[i][j] <= 85) {
                estado_temperaturas[i][j] = 'A';
            } else {
                estado_temperaturas[i][j] = 'C';
            }
        }
    }

    // Saída dos dados
    printf("Matriz de temperaturas:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%.1f ", matriz_temperaturas[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de temperaturas médias:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.1f ", temperaturas_medias[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de estados das temperaturas:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", estado_temperaturas[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        free(matriz_temperaturas[i]);
    } free(matriz_temperaturas);
    for (int i = 0; i < 5; i++) {
        free(temperaturas_medias[i]);
    } free(temperaturas_medias);
    for (int i = 0; i < 10; i++) {
        free(estado_temperaturas[i]);
    } free(estado_temperaturas);

    return 0;
}