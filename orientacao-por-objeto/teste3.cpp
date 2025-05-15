#include <stdio.h>
#include <string>

class Pessoa {
    public:
        std::string nome;
        int idade;
        std::string endereco;

        // Corrigido o construtor com a lista de inicialização
        Pessoa(std::string n, int i, std::string e, int c)
            : nome(n), idade(i), endereco(e), cpf(c) {}

        std::string getNome() {
            return nome;
        }

        int getCpf() {
            return gc();
        }

    private:
        int cpf;

        int gc() {
            return cpf;
        }
};

int main(void) {
    Pessoa pessoa("João", 30, "Rua A, 123", 123456789);
    printf("Nome: %s\n", pessoa.getNome().c_str());
    printf("Idade: %d\n", pessoa.idade);
    printf("Endereço: %s\n", pessoa.endereco.c_str());
    printf("CPF: %d\n", pessoa.getCpf());

    return 0; 
}