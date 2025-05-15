#include <stdio.h>
#include <string> // Para usar std::string

class Cavalo {
public:
    // Atributos inicializados
    int idade;
    float distanciaPercorrida;
    float peso;
    std::string nome;

    // Construtor inicializado
    Cavalo(int idade, float distanciaPercorrida, float peso, std::string nome): 
        idade(idade), distanciaPercorrida(distanciaPercorrida), peso(peso), nome(nome) {

        }
    
    // Ciração de métodos
    void CorridaCavalo(float distancia) {
        distanciaPercorrida += distancia;
        printf("Distancia percorrida pelo cavalo: %.2f\n", distanciaPercorrida);
    }

    void MostrarDados() {
        printf("Idade: %d\n", idade);
        printf("Distancia percorrida: %.2f\n", distanciaPercorrida);
        printf("Peso: %.2f\n", peso);
        printf("Nome: %s\n", nome.c_str());
    }
};

void function() {
    return; // This is a comment
}

int main(void) {
    printf("Hello, World!\n");

    // Instanciando o cavalo com o novo construtor
    Cavalo cavalo1(5, 0.0f, 450.0f, "Relâmpago");

    cavalo1.MostrarDados();

    float distancia = 10.5;
    cavalo1.CorridaCavalo(distancia);
    
    return 0;
}