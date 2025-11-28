#include <iostream>

// Cria estrutura para uma lista encadeada
struct No {
    int linha;
    int coluna;
    float valor;
    No* proximo;

    No(int l, int c, float v) : linha(l), coluna(c), valor(v), proximo(nullptr) {}
};

// Classe para matriz esparsa
class MatrizEsparsa {
    private:
        No* inicio;
        int tamanho;

    public:
        int linhas;
        int colunas;
        float** matriz;

        MatrizEsparsa(int lin, int col) {
            // Valida as dimensões passadas
            if (lin <= 0 || col <= 0) {
                throw std::invalid_argument("Dimensoes invalidas");
            }
            linhas = lin;
            colunas = col;
            matriz = new float*[linhas];
            for (int i = 0; i < linhas; i++) {
                matriz[i] = new float[colunas];
            }

            // Lógica para preencher a matriz e garante que seja esparsa
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    if (i == j) matriz[i][j] = i * j;
                    else matriz[i][j] = 0;
                }
            }

            inicio = nullptr;
            tamanho = 0;
        }

        ~MatrizEsparsa() {
            // Lógica para apagar a lista encadeada e a matriz
            No* atual = inicio;
            while (atual != nullptr) {
                No* temp = atual;
                atual = atual->proximo;
                delete temp;
            }
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
            std::cout << "Total de elementos nao-zero: " << tamanho << std::endl;
            No* atual = inicio;
            while (atual != nullptr) {
                std::cout << "Linha: " << atual->linha
                          << " Coluna: " << atual->coluna
                          << " Valor: " << atual->valor << std::endl;
                atual = atual->proximo;
            }
        }

        void comprimirMatriz() {
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    if (matriz[i][j] != 0) {
                        // Cria um novo nó para cada elemento diferente de zero
                        No* novoNo = new No(i, j, matriz[i][j]);
                        
                        if (inicio == nullptr) {
                            inicio = novoNo;
                        } else {
                            No* atual = inicio;
                            while (atual->proximo != nullptr) {
                                atual = atual->proximo;
                            }
                            atual->proximo = novoNo;
                        }
                        tamanho++;
                    }
                }
            }
        }

        float** descomprimirMatriz() {
            // Cria uma matriz temporária nula
            float** matriz_descomprimida = new float*[linhas];
            for (int i = 0; i < linhas; i++) {
                matriz_descomprimida[i] = new float[colunas];
                for (int j = 0; j < colunas; j++) {
                    matriz_descomprimida[i][j] = 0;
                }
            }

            // Preenche a matriz temporária com os valores da lista encadeada
            No* atual = inicio;
            while (atual != nullptr) {
                matriz_descomprimida[atual->linha][atual->coluna] = atual->valor;
                atual = atual->proximo;
            }

            return matriz_descomprimida;
        }
};

int main() {
    int linhas = 10; // Definindo número de linhas da matriz esparsa
    int colunas = 25; // Definindo número de colunas da matriz esparsa
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

    // Liberando memória da matriz descomprimida
    for (int i = 0; i < linhas; i++) {
        delete[] matriz_descomprimida_da_main[i];
    }
    delete[] matriz_descomprimida_da_main;

    return 0;
}