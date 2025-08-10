#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Definindo a palavra a ser adivinhada e inicializando variáveis
    char str[13] = "cavalo";
    char *tentativas = NULL; 
    char palavra_formada[6] = "______";
    char letra;
    int rodada = 0;
    int vida = 5;

    // Exibindo o cabeçalho do jogo
    printf("==========================\n");
    printf("JOGO DA FORCA\n");

    while (vida > 0) {
        // Variáveis locais auxiliares
        int count = 0;
        char temp_palavra[6];

        // Temporariamente armazena a palavra formada para comparação
        for (int i = 0; i < 6; i++) {
            temp_palavra[i] = palavra_formada[i];
        }

        // Menu de interação com validação de entrada
        int try = 0;
        do {
            try = 0;
            printf("==========================\n");
            printf("Digite a letra: ");
            scanf(" %c", &letra);
            printf("==========================\n");

            // Verifica se a letra já foi tentada
            for (int i = 0; i < rodada; i++) {
                if (tentativas[i] == letra) {
                    printf("Você já tentou essa letra!\n");
                    try = 1;
                }
        }
        } while (try == 1);

        // Sair do programa
        if (letra == '0') {
            printf("Você desistiu do jogo!\n");
            break;
        }
        
        // Armazenando letras tentadas
        tentativas = realloc(tentativas, (rodada + 1) * sizeof(char));
        if (tentativas == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }
        tentativas[rodada] = letra; 

        // Menu após interação do usuário
        printf("Vidas atuais: %d\n", vida);
        printf("Tentativas: ");
        for (int j = 0; j <= rodada; j++) { 
            printf("%c ", tentativas[j]);
        }

        // Verifica se a letra está na palavra e troca na palavra formada
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k <= rodada; k++) { 
                if (tentativas[k] == str[j]) {
                    palavra_formada[j] = str[j];
                }
            }
        }

        // Exibe a palavra formada até o momento
        printf("\nPalavra formada: ");
        for (int j = 0; j < 6; j++) {
            printf("%c ", palavra_formada[j]);
        }
        printf("\n");

        // Verifica se o jogador ganhou
        for (int j = 0; j < 6; j++) {
            if (palavra_formada[j] == str[j]) {
                count++;
            }

            if (count == 6) {
                printf("==========================\n");
                printf("Você ganhou!\n");
                printf("==========================\n");
                free(tentativas); 
                return 0;
            }
        }

        // Verifica se o jogador perdeu uma vida
        if (temp_palavra[0] == palavra_formada[0] && temp_palavra[1] == palavra_formada[1] && temp_palavra[2] == palavra_formada[2] && temp_palavra[3] == palavra_formada[3] && temp_palavra[4] == palavra_formada[4] && temp_palavra[5] == palavra_formada[5]) {
            vida--;
            printf("==========================\n");
            printf("Você errou! Perdeu uma vida.\n");
        }

        rodada++;
    }
 
    return 0;
}