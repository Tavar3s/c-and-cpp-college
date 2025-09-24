#include <iostream>

class Calculadora {
    public:
        int somar(int a, int b) {
            return a + b;
        }
        int subtrair(int a, int b) {
            return a - b;
        }
        int multiplicar(int a, int b) {
            return a * b;
        }
        double dividir(int a, int b) {
            if (b == 0) {
                std::cerr << "Erro: Divisão por zero!" << std::endl;
                return 0; // Retorna 0 ou pode lançar uma exceção
            }
            return static_cast<double>(a) / b;
        }
    
    Calculadora() {
        std::cout << "Calculadora inicializada!" << std::endl;
    }
};

int main() {
    Calculadora calc;

    float a, b;
    std::cout << "Digite dois números: ";
    std::cin >> a >> b;

    std::cout << "Soma: " << calc.somar(a, b) << std::endl;
    std::cout << "Subtração: " << calc.subtrair(a, b) << std::endl;
    std::cout << "Multiplicação: " << calc.multiplicar(a, b) << std::endl;
    std::cout << "Divisão: " << calc.dividir(a, b) << std::endl;

    return 0;
}