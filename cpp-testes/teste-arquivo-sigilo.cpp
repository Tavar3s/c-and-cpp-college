#include <iostream>
#include ".env/teste-sigilo.h"

int main() {
    std::cout << "Este é um arquivo de teste para sigilo: " << VALOR_TESTE << std::endl;
    std::cout << "Valor sem define: " << valor_sem_define << std::endl;
    return 0;
}