#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int linhas, int colunas) {
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    return matriz;
}

void gerar_imagem(int** imagem, int linhas, int colunas, int largura_trilho) {
    int centro_x = colunas / 2;
    int centro_y = linhas / 2;

    for (int y = 0; y < linhas; y++) {
        for (int x = 0; x < colunas; x++) {
            float valor = -0.05 * (x - centro_x) * (x - centro_x);
            valor += largura_trilho;
            valor -= abs(y - centro_y);
            if (valor < 0) valor = 0;
            if (valor > 64) valor = 64;
            imagem[y][x] = (int) valor;
        }
    }
}

void gerar_matriz_binaria(int** matriz_binaria, int linhas, int colunas, int** imagem) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (imagem[i][j] > 14) {
                matriz_binaria[i][j] = 1;
            } else {
                matriz_binaria[i][j] = 0;
            }
        }
    }
}

void converter_para_ascii(int** imagem, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (imagem[i][j] <= 10) {
                printf(".");
            } else if (imagem[i][j] <= 12) {
                printf("-");
            } else if (imagem[i][j] <= 14) {
                printf("=");
            } else {
                printf("#");
            }
        } printf("\n");
    }
}

int detectar_caminhos(int** matriz_binaria, int linhas, int colunas) {
    int caminhos = 0;
    int temp = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz_binaria[i][j] == 1) {
                temp++;
            } else {
                temp = 0;
            }
            if (temp == 3) {
                caminhos++;
                break;
            }
        } temp = 0;
    }
    return caminhos;
}

int* posicao_inicial_caminho(int** matriz_binaria, int linhas, int colunas, int tamanho_vetor) {
    if (colunas < 10) {
        return NULL;
    }

    int* vetor = malloc(tamanho_vetor * sizeof(int));
    int temp = 0;
    int count = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz_binaria[i][j] == 1) {
                temp++;
            } else {
                temp = 0;
            }
            if (temp == 3) {
                vetor[count] = j-2;
                count++;
                break;
            }
        } 
    }
    
    return vetor;
}

int main(void) {
    // Definindo variáveis
    int linhas, colunas, largura_trilho, caminhos;
    int** imagem = NULL;
    int** matriz_binaria = NULL;
    void* posicao = NULL;

    // Lendo os parâmetros de entrada
    scanf("%d %d %d", &linhas, &colunas, &largura_trilho);
    if (linhas <= 0 || colunas <= 0 || largura_trilho <= 0) {
        fprintf(stderr, "Erro: Dimensões inválidas.\n");
        return 1;
    }

    // Alocando memória para as matrizes
    matriz_binaria = aloca_matriz(linhas, colunas);
    imagem = aloca_matriz(linhas, colunas);

    // Gerando a imagem e a matriz binária
    gerar_imagem(imagem, linhas, colunas, largura_trilho);
    gerar_matriz_binaria(matriz_binaria, linhas, colunas, imagem);

    // Exibindo a imagem
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%3d ", imagem[i][j]);
        } printf("\n");
    }

    // Exibindo a imagem com símbolos ASCII
    converter_para_ascii(imagem, linhas, colunas);

    // Detectando caminhos possíveis
    caminhos = detectar_caminhos(matriz_binaria, linhas, colunas);
    printf("Caminhos = %d\n", caminhos);

    // Mostrando as posições iniciais dos caminhos
    posicao = posicao_inicial_caminho(matriz_binaria, linhas, colunas, caminhos);

    for (int i = 0; i < caminhos; i++){
        printf("%d ", ((int*)posicao)[i]);
    } printf("\n");

    // Liberando memória alocada
    for (int i = 0; i < linhas; i++) {
        free(imagem[i]);
        free(matriz_binaria[i]);
    }
    free(imagem);
    free(matriz_binaria);
    free(posicao);

    
    return 0;
}