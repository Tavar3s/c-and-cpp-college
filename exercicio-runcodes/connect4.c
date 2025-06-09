#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char** aloca_tabuleiro(int LINHAS, int COLUNAS) {
    char** tabuleiro = (char**) malloc(LINHAS * sizeof(char*));
    for (int i = 0; i < LINHAS; i++) {
        tabuleiro[i] = (char*) malloc(COLUNAS * sizeof(char));
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '.';
        }
    }
return tabuleiro;
}

void realizar_jogada(char** tabuleiro, int LINHAS, int coluna, char jogador) {
    for (int i = LINHAS - 1; i >= 0; i--) {
        if (tabuleiro[i][coluna] == '.') {
            tabuleiro[i][coluna] = jogador;
            break;
        }
    }
}

// Função para verificar se há um vencedor
bool verificar_linha(char** tabuleiro, int LINHAS, int COLUNAS, char jogador) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS - 3; j++) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i][j + 1] == jogador &&
                tabuleiro[i][j + 2] == jogador && tabuleiro[i][j + 3] == jogador) {
                return true;
            }
        }
    }
    return false;
}

bool verificar_coluna(char** tabuleiro, int LINHAS, int COLUNAS, char jogador) {
    for (int j = 0; j < COLUNAS; j++) {
        for (int i = 0; i < LINHAS - 3; i++) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i + 1][j] == jogador &&
                tabuleiro[i + 2][j] == jogador && tabuleiro[i + 3][j] == jogador) {
                return true;
            }
        }
    }
    return false;
}

bool verificar_diagonal(char** tabuleiro, int LINHAS, int COLUNAS, char jogador) {
    // Verifica diagonais de cima para baixo
    for (int i = 0; i < LINHAS - 3; i++) {
        for (int j = 0; j < COLUNAS - 3; j++) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i + 1][j + 1] == jogador &&
                tabuleiro[i + 2][j + 2] == jogador && tabuleiro[i + 3][j + 3] == jogador) {
                return true;
            }
        }
    }

    // Verifica diagonais de baixo para cima
    for (int i = 3; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS - 3; j++) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i - 1][j + 1] == jogador &&
                tabuleiro[i - 2][j + 2] == jogador && tabuleiro[i - 3][j + 3] == jogador) {
                return true;
            }
        }
    }

    return false;
}

int main(){
    char** board = NULL;
    int rows = 6;
    int cols = 7;
    char jogador = 'X';

    // Allocate memory for the board
    board = aloca_tabuleiro(6, 7);

    while (1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        int coluna;

        scanf("%d", &coluna);
        if (coluna < 0 || coluna >= cols) {
            printf("Coluna inválida. Tente novamente.\n");
            continue;
        }

        realizar_jogada(board, rows, coluna-1, jogador);

        if (verificar_linha(board, rows, cols, jogador) || 
            verificar_coluna(board, rows, cols, jogador) || 
            verificar_diagonal(board, rows, cols, jogador)) {
            printf("Vencedor: '%c'\n", jogador);
            break;
        }

         if (jogador == 'X') {
            jogador = 'O';
        } else {
            jogador = 'X';
        }

        system("cls"); // Limpa a tela para o próximo turno
    }
}
