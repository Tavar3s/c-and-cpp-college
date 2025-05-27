#include <iostream>
#include <stdlib.h>
#include <windows.h>

// Função para alocar um campo bidimensional binario
int** alocaCampo(int linhas, int colunas) {
    int** campo = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        campo[i] = new int[colunas];
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            campo[i][j] = 0; // Inicializa o campo com zeros
        }
    }
    campo[0][0] = 1; // Marca a posição inicial do robô
    std::cout << "Campo alocado com sucesso!" << std::endl;

    return campo;
}

// Função para deslocar o robô no campo
void deslocaRobot(int** campo, int linhas, int colunas, char tecla) {
    // Encontra a posição atual do robô
    int posX = -1, posY = -1;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (campo[i][j] == 1) {
                posX = i;
                posY = j;
                break;
            }
        }
        if (posX != -1) break;
    }

    // Desloca o robô com base na tecla pressionada
    campo[posX][posY] = 0; // Limpa a posição atual
    switch (tecla) {
        case 'w': // Cima
            if (posX > 0) campo[posX - 1][posY] = 1;
            break;
        case 's': // Baixo
            if (posX < linhas - 1) campo[posX + 1][posY] = 1;
            break;
        case 'a': // Esquerda
            if (posY > 0) campo[posX][posY - 1] = 1;
            break;
        case 'd': // Direita
            if (posY < colunas - 1) campo[posX][posY + 1] = 1;
            break;
        default:
            campo[posX][posY] = 1; // Retorna à posição original se tecla inválida
            break;
    }
}

char retonarletra(void) {
    for (int i=0; i < 1000; i++){
        if (GetAsyncKeyState('W') & 0x8000) {
            return 'w'; // Cima
        } else if (GetAsyncKeyState('S') & 0x8000) {
            return 's'; // Baixo
        } else if (GetAsyncKeyState('A') & 0x8000) {
            return 'a'; // Esquerda
        } else if (GetAsyncKeyState('D') & 0x8000) {
            return 'd'; // Direita
        }
    }
    return ' '; // Nenhuma tecla válida pressionada
}

int main(void){
    // Inicializando variaveis
    int** campo= NULL;
    int i, j;

    // Atribuindo valores para as variaveis
    std::cout << "Digite o tamanho do campo: ";
    std::cin >> i;
    std::cin >> j;
    campo = alocaCampo(i, j);

    while (1) {
        // Letra pressionada
        char tecla;

        tecla = retonarletra(); // Captura a tecla pressionada

        deslocaRobot(campo, i, j, tecla); // Desloca o robô com base na tecla

        // Exibe o campo
        for (int x = 0; x < i; x++) {
            for (int y = 0; y < j; y++) {
                if (campo[x][y] == 1) {
                    std::cout << "R "; // R representa o robô
                } else {
                    std::cout << ". "; // . representa um espaço vazio
                }
            }
            std::cout << std::endl;
        } std::cout << std::endl;

        Sleep(500); // Pausa de 1 segundo (1500 milissegundos)
        system("cls"); // Limpa o console
    }

    return 0;
}