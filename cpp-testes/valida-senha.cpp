#include <iostream>
#include <string>
#include <cctype>



int main() {
    int vezes = 0;
    std::cout << "Validador de Senhas" << std::endl;

    std::cout << "Digite o número de vezes que deseja validar senhas: ";
    std::cin >> vezes;

    for (int i = 0; i < vezes; i++) {
        std::string senha;
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        bool temMaiuscula = false, temMinuscula = false, 
        temDigito = false, temEspecial = false, temTamanho = senha.length() >= 8;
        const std::string especiais = "!@#$%^&*()-_=+[]{}|;:',.<>?";

        for (char c : senha) {
            if (std::isupper(c)) temMaiuscula = true;
            else if (std::islower(c)) temMinuscula = true;
            else if (std::isdigit(c)) temDigito = true;
            else if (especiais.find(c) != std::string::npos) temEspecial = true;
        }

        if (!temMaiuscula || !temMinuscula || !temDigito || !temEspecial || !temTamanho) {
            std::cout << "Senha fraca" << std::endl;
        } else {
            std::cout << "Senha forte" << std::endl;
        }
    }

    return 0;
}