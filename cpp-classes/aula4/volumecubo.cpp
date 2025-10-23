#include <iostream>
#include <cmath>

using namespace std;

class Cubo {
    public:
        float lado;
        Cubo(double lado_recebido) {
            lado = lado_recebido;
        }

        ~Cubo() {
            cout << "Destruindo cubo!" << endl;
        }

        virtual double volume() {
            return lado * lado * lado;
        }
};

class Esfera: public Cubo {
    public:
        float raio;
        Esfera(double raio_recebido): Cubo(raio_recebido) {
            raio = raio_recebido;
        }

        ~Esfera() {
            cout << "Destruindo esfera!" << endl;
        }

        double volume() override {
            return (4.0/3.0) * M_PI * lado * lado * lado;
        }
};

class Cone: public Esfera {
    public:
        float altura;
        float raio;
        Cone(double raio_recebido, double altura_recebida): Esfera(raio_recebido) {
            altura = altura_recebida;
            raio = raio_recebido;
        }

        ~Cone() {
            cout << "Destruindo cone!" << endl;
        }

        double volume() override {
            return (1.0/3.0) * M_PI * raio * raio * altura;
        }
};

int main() {
    Cubo cubo(5);
    Esfera esfera(3);
    Cone cone(3, 5);

    cout << "Volume do cubo: " << cubo.volume() << endl;
    cout << "Volume da esfera: " << esfera.volume() << endl;
    cout << "Volume do cone: " << cone.volume() << endl;

    return 0;
}