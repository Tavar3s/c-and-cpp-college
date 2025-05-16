#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char str[13] = "cavalo";
    char tentativas[6];
    char palavra_formada[6] = "______";

    char letra;
    int rodada = 0;
    int vida = 5;

    printf("==========================\n");
    printf("JOGO DA FORCA\n");
    printf("==========================\n");

    while (vida > 0) {
        int count = 0;
        char temp_palavra[6];

        for (int i = 0; i < 6; i++) {
            temp_palavra[i] = palavra_formada[i];
        }

        printf("Digite a letra: ");
        scanf(" %c", &letra);
        printf("==========================\n");

        if (letra == '0') {
            printf("Você desistiu do jogo!\n");
            break;
        }

        tentativas[rodada] = letra;

        printf("Vidas atuais: %d\n", vida);
        printf("Tentativas: ");
        for (int j = 0; j < 6; j++) {
            printf("%c ", tentativas[j]);
        }

        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if (tentativas[k] == str[j]) {
                    palavra_formada[j] = str[j];
                }
            }
        }

        printf("\nPalavra formada: ");
        for (int j = 0; j < 6; j++) {
            printf("%c ", palavra_formada[j]);
        }
        printf("\n");

        for (int j = 0; j < 6; j++) {
            if (palavra_formada[j] == str[j]) {
                count++;
            }

            if (count == 6) {
                printf("==========================\n");
                printf("Você ganhou!\n");
                printf("==========================\n");
                return 0;
            }
        }

        if (temp_palavra[0] == palavra_formada[0] && temp_palavra[1] == palavra_formada[1] && temp_palavra[2] == palavra_formada[2] && temp_palavra[3] == palavra_formada[3] && temp_palavra[4] == palavra_formada[4] && temp_palavra[5] == palavra_formada[5]) {
            vida--;
            printf("==========================\n");
            printf("Você errou! Perdeu uma vida.\n");
            printf("==========================\n");
        }

        rodada++;
    }
    


    return 0;
}