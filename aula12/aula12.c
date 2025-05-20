#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funções presentes no código
void* alocar_matriz(int linhas, int colunas, size_t tamanho_elemento) {
    void** matriz = (void**) malloc(linhas * sizeof(void*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = malloc(colunas * tamanho_elemento);
    }
    return matriz;
}

void liberar_matriz(void** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void media_temperaturas(float** matriz_temperaturas, float** temperaturas_medias, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            temperaturas_medias[i][j] = 0;
            for (int k = i * 2; k < (i + 1) * 2; k++) {
                for (int l = j * 2; l < (j + 1) * 2; l++) {
                    temperaturas_medias[i][j] += matriz_temperaturas[k][l];
                }
            }
            temperaturas_medias[i][j] /= 4.0;
        }
    }
}

void imprimir_estados(char** estados, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c ", estados[i][j]);
        }
        printf("\n");
    }
}

void imprimir_matriz(float** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void classificar_temperaturas(float** temperaturas, char** estados, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (temperaturas[i][j] <= 65) {
                estados[i][j] = 'P'; // Padrão
            } else if (temperaturas[i][j] <= 85) {
                estados[i][j] = 'A'; // Alta
            } else {
                estados[i][j] = 'C'; // Crítica
            }
        }
    }
}

int main() {
    // Alocação de memória para um vetor de decimais e rand definido
    srand(time(NULL));
    float** matriz_temperaturas = NULL;
    float** temperaturas_medias = NULL;
    char** estado_temperaturas = NULL;

    // Alocação de memória para as matrizes usando a função
    matriz_temperaturas = (float**) alocar_matriz(10, 10, sizeof(float));
    temperaturas_medias = (float**) alocar_matriz(5, 5, sizeof(float));
    estado_temperaturas = (char**) alocar_matriz(5, 5, sizeof(char));

    // Preenchendo a matriz de temperaturas com valores aleatórios
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz_temperaturas[i][j] = (float)(rand() % 100);
        }
    }

    // Calculando a média das temperaturas em janelas 2x2
    media_temperaturas(matriz_temperaturas, temperaturas_medias, 5, 5);

    // Classificando as temperaturas médias
    classificar_temperaturas(temperaturas_medias, estado_temperaturas, 5, 5);

    // Saída dos dados
    printf("Matriz de temperaturas:\n");
    imprimir_matriz(matriz_temperaturas, 10, 10);

    printf("\nMatriz de temperaturas médias:\n");
    imprimir_matriz(temperaturas_medias, 5, 5);

    printf("\nMatriz de estados das temperaturas:\n");
    imprimir_estados(estado_temperaturas, 5, 5);

    // Liberando a memória alocada
    liberar_matriz((void**) matriz_temperaturas, 10);
    liberar_matriz((void**) temperaturas_medias, 5);
    liberar_matriz((void**) estado_temperaturas, 5);

    return 0;
}