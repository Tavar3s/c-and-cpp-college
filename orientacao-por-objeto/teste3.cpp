#include <iostream>
#include <string>

class Pessoa {
    public:
        std::string nome;
        int idade;
        std::string endereco;

        Pessoa(std::string n, int i, std::string e, int c): 
            nome(n), idade(i), endereco(e), cpf(c) {}

        std::string getNome() {
            return nome;
        }

        int getCpf() {
            return pedirSenha();
        }

    private:
        int cpf;

        int pedirSenha() {
            std::string temp;
            std::cout << "Digite a senha: ";
            std::cin >> temp;
            std::string senha = "Cavalo_Antonio";
            if (temp != senha) {
                std::cout << "Senha incorreta\n";
                return 0;
            }
            return cpf;
        }
};

int main(void) {
    Pessoa ronaldo("Ronaldo", 35, "Rua A", 123456789);
    std::cout << "Nome: " << ronaldo.getNome() << std::endl;
    std::cout << "CPF: " << ronaldo.getCpf() << std::endl;

    return 0; 
}