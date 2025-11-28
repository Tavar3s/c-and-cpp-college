#include <iostream>

class MatrizEsparsa {
    public:
        int linhas;
        int colunas;
        float** matriz;

        // Variáveis para armazenar a matriz comprimida
        int* linha_valores = new int[capacidade];
        int* coluna_valores = new int[capacidade];
        float* valores = new float[capacidade];
        int capacidade = 2;
        int contador = 0;

        MatrizEsparsa(int lin, int col) {
            // Verificação de dimensão válida
            if (lin <= 0 || col <= 0) {
                throw std::invalid_argument("Dimensoes invalidas");
            }
            linhas = lin;
            colunas = col;
            matriz = new float*[linhas];
            for (int i = 0; i < linhas; i++) {
                matriz[i] = new float[colunas];
            }

            // Lógica para popular matriz que garante ser uma matriz esparsa para ordem maior que 2
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    if (i == j) matriz[i][j] = i * j;
                    else matriz[i][j] = 0;
                }
            }
        }

        ~MatrizEsparsa() {
            delete[] linha_valores;
            delete[] coluna_valores;
            delete[] valores;
            for (int i = 0; i < linhas; i++) {
                delete[] matriz[i];
            }
            delete[] matriz;
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-" << std::endl;
            std::cout << "Matriz liberada da memoria." << std::endl;
        }

        void imprimirMatriz() {
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-" << std::endl;
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    std::cout << matriz[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-" << std::endl;
        }

        void imprimirCompressao() {
            std::cout << "Total de elementos nao-zero: " << contador << std::endl;
            for (int i = 0; i < contador; i++) {
                std::cout << "Linha: " << linha_valores[i]
                          << " Coluna: " << coluna_valores[i]
                          << " Valor: " << valores[i] << std::endl;
            }
        }

        void comprimirMatriz() {
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    if (matriz[i][j] != 0) {
                        if (contador >= capacidade) {
                            int nova_cap = capacidade * 2;
                            int* linha_temp = new int[nova_cap];
                            int* coluna_temp = new int[nova_cap];
                            float* valores_temp = new float[nova_cap];

                            for (int k = 0; k < contador; k++) {
                                linha_temp[k] = linha_valores[k];
                                coluna_temp[k] = coluna_valores[k];
                                valores_temp[k] = valores[k];
                            }

                            delete[] linha_valores;
                            delete[] coluna_valores;
                            delete[] valores;
                            linha_valores = linha_temp;
                            coluna_valores = coluna_temp;
                            valores = valores_temp;
                            capacidade = nova_cap;
                        }

                        linha_valores[contador] = i;
                        coluna_valores[contador] = j;
                        valores[contador] = static_cast<float>(matriz[i][j]);
                        contador++;
                    }
                }
            }
        }

        float** descomprimirMatriz() {
            int contador_descomprimir = 0;
            float** matriz_descomprimida = new float*[linhas];
            for (int i = 0; i < linhas; i++) {
                matriz_descomprimida[i] = new float[colunas];
            }

            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    if (linha_valores[contador_descomprimir] == i &&
                        coluna_valores[contador_descomprimir] == j) {
                        matriz_descomprimida[i][j] = valores[contador_descomprimir];
                        contador_descomprimir++;
                    } else {
                        matriz_descomprimida[i][j] = 0;
                    }
                }
            }

            return matriz_descomprimida;
        }
};

int main() {
    int linhas = 10;
    int colunas = 25;
    float** matriz_descomprimida_da_main;

    // Criando objeto MatrizEsparsa
    MatrizEsparsa matriz(linhas, colunas);

    // Chamando funções do objeto MatrizEsparsa
    matriz.imprimirMatriz();
    matriz.comprimirMatriz();
    matriz.imprimirCompressao();

    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-" << std::endl;
    matriz_descomprimida_da_main = matriz.descomprimirMatriz();

    // Imprimindo matriz descomprimida
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << matriz_descomprimida_da_main[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}