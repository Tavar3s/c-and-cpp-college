#include <stdio.h>


class UsuarioBanco
{
private:
    float dinheiro_usuario;
    int senha_usuario;
    int senha_correta = 1234;
public:
    void set_dinheiro_usuario(float dinheiro_usuario) {
        this->dinheiro_usuario = dinheiro_usuario;
    }

    float get_dinheiro_usuario() {
        return dinheiro_usuario;
    }

    void set_senha_usuario(int senha_usuario) {
        this->senha_usuario = senha_usuario;
    }

    int get_senha_usuario() {
        return senha_usuario;
    }

    int get_senha_correta() {
        return senha_correta;
    }
};

int main() {
    UsuarioBanco usuario1;
    usuario1.set_dinheiro_usuario(1000.0f);   
    usuario1.set_senha_usuario(1234);
    printf("O saldo do usuario e: %.2f\n", usuario1.get_dinheiro_usuario());
    printf("A senha do usuario e: %d\n", usuario1.get_senha_usuario());

    return 0;
}