#include <stdio.h> 
#include <string> // Para usar std::string
#include <stdlib.h> // Para usar rand()


class Personagem {
    public:
    // Atributos inicializados
    int idade;
    float altura;
    float vida;
    float ataque;
    std::string nome;

    // Construtor inicializado
    Personagem(int idade, float altura, float vida, std::string nome, float ataque): 
        idade(idade), altura(altura), vida(vida), ataque(ataque), nome(nome) {
        }

    // Ciração de métodos
    float receberDano(float danoRecebido) {
        vida -= danoRecebido;
        return vida;
    }

    float curar(float cura) {
        vida += cura;
        return vida;
    }
    
};


int main(void) {
    Personagem personagem1(25, 1.75f, 100.0f, "Guerreiro", 10.0f);
    Personagem personagem2(30, 1.80f, 120.0f, "Mago", 15.0f);

    personagem1.receberDano(personagem2.ataque);
    printf("Vida do personagem 1 após receber dano: %.2f\n", personagem1.vida);

    return 0; 
}