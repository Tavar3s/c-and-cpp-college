#include <iostream>

class Medidas {
    public:
        float* valores_medidas;
        float* valores_ordenados;
        float max_medida;
        float min_medida;
        float moda_medida;
        int tam_vetor;

        Medidas(int tam_vetor) {
            if (tam_vetor <= 0) {
                std::cerr << "Tamanho do vetor deve ser maior que zero." << std::endl;
                exit(1);
            }
            valores_medidas = new float[tam_vetor];
            valores_ordenados = new float[tam_vetor];
            this->tam_vetor = tam_vetor;

        }

        ~Medidas() {
            delete[] valores_medidas;
            delete[] valores_ordenados;
            std::cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
            std::cout << "Memoria liberada com sucesso." << std::endl;
        }

        void busca_valor(float valor_procurado) {
            int count = 0;
            for (int i = 0; i < tam_vetor; i++) {
                if (valores_medidas[i] == valor_procurado) {
                    count++;
                }
            }
            if (count == 0) {
                std::cout << "Valor " << valor_procurado << " nao encontrado no vetor." << std::endl;
                return;
            } else {
                int* indices = new int[count];
                int index = 0;
                for (int i = 0; i < tam_vetor; i++) {
                    if (valores_medidas[i] == valor_procurado) {
                        indices[index] = i;
                        index++;
                    }
                }
                for (int i = 0; i < count; i++) {
                    std::cout << "Valor " << valor_procurado << " encontrado no indice: " << indices[i] << std::endl;
                }
            }
            return;
        }

        void busca_com_parada(float valor_procurado) {
            for (int i = 0; i < tam_vetor; i++) {
                if (valores_medidas[i] == valor_procurado) {
                    std::cout << "Valor " << valor_procurado << " encontrado no indice: " << i << std::endl;
                    return;
                }
            }
            
            std::cout << "Valor " << valor_procurado << " nao encontrado no vetor." << std::endl;
        }

        void max_min() {
            max_medida = valores_medidas[0];
            min_medida = valores_medidas[0];

            for (int i = 1; i < tam_vetor; i++) {
                if (valores_medidas[i] > max_medida) {
                    max_medida = valores_medidas[i];
                }
                if (valores_medidas[i] < min_medida) {
                    min_medida = valores_medidas[i];
                }
            }

            std::cout << "Maximo: " << max_medida << ", Minimo: " << min_medida << std::endl;
        }

        void moda() {
            int max_count = 0;
            float moda = valores_medidas[0];

            for (int i = 0; i < tam_vetor; i++) {
                int count = 0;
                for (int j = 0; j < tam_vetor; j++) {
                    if (valores_medidas[j] == valores_medidas[i]) {
                        count++;
                    }
                }
                if (count > max_count) {
                    max_count = count;
                    moda = valores_medidas[i];
                }
            }

            moda_medida = moda;
            std::cout << "Moda: " << moda_medida << std::endl;
        }

        void bubble_sort() {
            for (int i = 0; i < tam_vetor - 1; i++) {
                for (int j = 0; j < tam_vetor - i - 1; j++) {
                    if (valores_medidas[j] > valores_medidas[j + 1]) {
                        float temp = valores_medidas[j];
                        valores_medidas[j] = valores_medidas[j + 1];
                        valores_medidas[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < tam_vetor; i++) {
                valores_ordenados[i] = valores_medidas[i];
            }
            std::cout << "Vetor ordenado: ";
            for (int i = 0; i < tam_vetor; i++) {
                std::cout << valores_ordenados[i] << " ";
            }   
        }
};

int main() {
    int tam_vetor;
    float valor_procurado;
    std::cout << "Digite o tamanho do vetor de medidas: ";
    std::cin >> tam_vetor;

    Medidas medidas(tam_vetor);
    for (int i = 0; i < tam_vetor; i++) {
        std::cout << "Digite o valor da medida " << (i + 1) << ": ";
        std::cin >> medidas.valores_medidas[i];
    }

    std::cout << "Digite o valor a ser procurado: ";
    std::cin >> valor_procurado;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;

    medidas.busca_valor(valor_procurado);
    medidas.busca_com_parada(valor_procurado);
    medidas.max_min();
    medidas.moda();
    medidas.bubble_sort();

    return 0;
}