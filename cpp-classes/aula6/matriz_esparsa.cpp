#include <iostream>

class MatrizEsparsa {
    public:
        int linhas;
        int colunas;
        float** matriz;

        MatrizEsparsa(int lin, int col) {
            linhas = lin;
            colunas = col;
            matriz = new int*[linhas];
            for (int i = 0; i < linhas; i++) {
                matriz[i] = new int[colunas];
            }
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    if (i == j) matriz[i][j] = i * j;
                    else matriz[i][j] = 0;
                }
            }
        }

        ~MatrizEsparsa() {
            delete[] matriz;
        }
};

int main() {
    int linhas = 10;
    int colunas = 25;

    // aloca matriz dinamicamente
    int** matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
    }

    // preenche e imprime a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (i == j) matriz[i][j] = i * j;
            else matriz[i][j] = 0;
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // começar com capacidade > 0
    int capacidade = 2;
    int contador = 0;
    int* linha_valores = new int[capacidade];
    int* coluna_valores = new int[capacidade];
    float* valores = new float[capacidade];

    // compressão: coleta elementos não-zero
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] != 0) {
                if (contador >= capacidade) {
                    // dobra a capacidade
                    int nova_cap = capacidade * 2;
                    int* linha_temp = new int[nova_cap];
                    int* coluna_temp = new int[nova_cap];
                    float* valores_temp = new float[nova_cap];

                    // copia os existentes
                    for (int k = 0; k < contador; k++) {
                        linha_temp[k] = linha_valores[k];
                        coluna_temp[k] = coluna_valores[k];
                        valores_temp[k] = valores[k];
                    }

                    // libera os antigos e substitui
                    delete[] linha_valores;
                    delete[] coluna_valores;
                    delete[] valores;
                    linha_valores = linha_temp;
                    coluna_valores = coluna_temp;
                    valores = valores_temp;
                    capacidade = nova_cap;
                }

                // adiciona novo elemento
                linha_valores[contador] = i;
                coluna_valores[contador] = j;
                valores[contador] = static_cast<float>(matriz[i][j]);
                contador++;
            }
        }
    }

    // imprime listas (usa contador, não capacidade)
    std::cout << "\nTotal de elementos nao-zero: " << contador << std::endl;
    for (int i = 0; i < contador; i++) {
        std::cout << "Linha: " << linha_valores[i]
                  << " Coluna: " << coluna_valores[i]
                  << " Valor: " << valores[i] << std::endl;
    }

    // libera memória
    delete[] linha_valores;
    delete[] coluna_valores;
    delete[] valores;
    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}