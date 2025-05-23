#include <stdio.h>
#include <stdlib.h>

void boneco(int vida) {
    // Exibe o boneco de acordo com o número de vidas restantes
    switch (vida) {
        case 5:
            printf("  O \n");
            printf(" /|\\\n");
            printf(" / \\\n");
            break;
        case 4:
            printf("  O \n");
            printf(" /|\\\n");
            printf(" / \n");
            break;
        case 3:
            printf("  O \n");
            printf(" /|\\\n");
            printf(" \n");
            break;
        case 2:
            printf("  O \n");
            printf(" /| \n");
            printf(" \n");
            break;
        case 1:
            printf("  O \n");
            printf("  | \n");
            printf(" \n");
            break;
        case 0:
            printf("  O-- \n");
            printf(" \n");
            printf(" \n");
            break;
    }
}

int tamanho(char *str) {
    // Retorna o tamanho da string
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char minusculo(char letra) {
    // Converte a letra para minúsculo
    if (letra >= 'A' && letra <= 'Z') {
        return letra + 32;
    }
    return letra;
}

int main(void) {
    // Definindo a palavra a ser adivinhada e inicializando variáveis
    char *str = "hexagono"; // (NÃO USE ACENTOS OU CARACTERES ESPECIAIS)
    int valor_padrao = tamanho(str);
    char *tentativas = NULL; 
    char palavra_formada[valor_padrao]; // Inicializa a palavra formada
    char letra;
    int rodada = 0;
    int vida = 5;
    for (int i = 0; i < valor_padrao; i++) {
        palavra_formada[i] = '_'; // Inicializa a palavra formada com '_'
    }
    
    // Exibindo o cabeçalho do jogo
    printf("==========================\n");
    printf("       JOGO DA FORCA      \n");

    while (vida > 0) {
        // Variáveis locais auxiliares
        int count = 0;
        char temp_palavra[valor_padrao];

        // Temporariamente armazena a palavra formada para comparação
        for (int i = 0; i < valor_padrao; i++) {
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

            // Converte a letra para minúsculo
            letra = minusculo(letra);

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
            printf("===========================\n");
            break;
        }
        
        // Armazenando letras tentadas
        tentativas = realloc(tentativas, (rodada + 1) * sizeof(char));
        if (tentativas == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }
        tentativas[rodada] = letra; 

        // Verifica se a letra está na palavra e troca na palavra formada
        for (int j = 0; j < valor_padrao; j++) {
            for (int k = 0; k <= rodada; k++) { 
                if (tentativas[k] == str[j]) {
                    palavra_formada[j] = str[j];
                }
            }
        }

        // Verifica se o jogador perdeu uma vida
        int is_same = 1;
        for (int i = 0; i < valor_padrao; i++) {
            if (temp_palavra[i] != palavra_formada[i]) {
                is_same = 0; 
                break;
            }
        }

        if (is_same) {
            vida--;
            printf("Você errou! Perdeu uma vida.\n");
            printf("==========================\n");
        }


        // Menu após interação do usuário
        printf("Vidas atuais: %d\n", vida);
        boneco(vida);
        printf("Tentativas: ");
        for (int j = 0; j <= rodada; j++) { 
            printf("%c ", tentativas[j]);
        }

        
        // Exibe a palavra formada até o momento
        printf("\nPalavra formada: ");
        for (int j = 0; j < valor_padrao; j++) {
            printf("%c ", palavra_formada[j]);
        }
        printf("\n");

        // Verifica se o jogador ganhou
        for (int j = 0; j < valor_padrao; j++) {
            if (palavra_formada[j] == str[j]) {
                count++;
            }

            if (count == valor_padrao) {
                printf("==========================\n");
                printf("Você ganhou!\n");
                printf("==========================\n");
                free(tentativas); 
                return 0;
            }
        }

        rodada++;
    }
 
    return 0;
}