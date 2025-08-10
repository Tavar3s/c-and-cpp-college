#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimir_mensagem(char *mensagem) {
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%s\n", mensagem);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

int main(){
    char mensagem[255] = "Bem-vindo ao curso de C!";

    imprimir_mensagem(mensagem);

    int tamanho = strlen(mensagem);
    printf("Tamanho da mensagem: %d\n", tamanho);

    char nova_palavra[255];
    printf("Digite uma nova palavra: ");
    scanf("%s", nova_palavra);

    printf("%d \n", strcmp(mensagem, nova_palavra));
    if (strcmp(mensagem, nova_palavra) == 0) {
        printf("As mensagens são iguais!\n");
    } else {
        printf("As mensagens são diferentes!\n");
    }

    return 0;
}