#include <stdio.h>

int main(void) {
    int ano_ingresso;

    while (ano_ingresso != 2025) {
        scanf("%d", &ano_ingresso);
        
        if (ano_ingresso == 2025) {
            printf("Acesso Permitido\n");
        } else {
            printf("Senha Invalida\n");
        }
    }

    return 0;
}