#include <stdio.h>
#include <string>

class Teste {
    public:
        int valor;
        float valor2;
        std::string nome;

        // Construtor padrão atualizado para inicializar valorPrivado
        Teste(int v, float v2, std::string n, int vp) 
            : valor(v), valor2(v2), nome(n), valorPrivado(vp) {}

        // Método público para acessar valorPrivado
        int getValorPrivado(void) {
            return valorPrivado;
        }

        // o valor fica na aba privada, agr a funçaõ de retorno não, essa é publica

    private:
        int valorPrivado;
};

int main() {
    // Instanciando a classe Teste com o novo parâmetro para valorPrivado
    Teste t(10, 20.5, "Teste", 69);
    printf("Valor Privado: %d\n", t.getValorPrivado());

    return 0;
}