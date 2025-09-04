#include <iostream>
#include <algorithm> // Para std::copy

int main() {
    int* dynamicArray = nullptr;
    size_t capacity = 0;
    size_t size = 0;

    std::cout << "Digite valores inteiros (digite um valor nao-inteiro para parar):" << std::endl;

    int value;
    while (std::cin >> value) {
        if (size == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            int* tempArray = new int[newCapacity]; // 1. Aloca novo array maior

            // 2. Copia elementos antigos para o novo array
            if (dynamicArray != nullptr) {
                std::copy(dynamicArray, dynamicArray + size, tempArray);
            }

            // 3. Desaloca o array antigo
            delete[] dynamicArray;

            // 4. Atualiza o ponteiro e a capacidade
            dynamicArray = tempArray;
            capacity = newCapacity;
            std::cout << "Array expandido para capacidade " << capacity << std::endl;
        }

        dynamicArray[size] = value;
        size++;
    }

    std::cout << "\nValores inseridos:" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    // Libera a memória alocada
    delete[] dynamicArray;
    dynamicArray = nullptr;

    return 0;
}