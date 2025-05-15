#include <stdio.h>

int main(void) {
    // Parte 1 - Criação dos personagens
    int rodadas, dificuldade, agilidade, carisma;
    float vontade;

    int vida = 10;

    // Leitura dos dados de entrada
    scanf("%d", &rodadas);
    scanf("%d", &dificuldade);
    scanf("%f", &vontade);
    scanf("%d", &agilidade);
    scanf("%d", &carisma);

    // Validação dos dados de entrada
    if ( vontade < 0 || vontade > 1 || agilidade < 0 || carisma < 0 || dificuldade < 0 || rodadas < 0) {
        printf("erro: intervalo dos atributos\n");
        return -2;
    }

    if ( agilidade + carisma != 10) {
        printf("erro: soma dos atributos\n");
        return -1;
    }

    // Cálculo da habilidade
    float habilidade = (agilidade * 0.6 + carisma * 0.5) * vontade;

    printf("Dificuldade = %d\n", dificuldade);
    printf("Habilidade = %.2f\n", habilidade);

    // Parte 2 - Simulação de rodadas

    // Calculo do dano
    int dano = dificuldade - (int)habilidade;

    // Aplicação do dano
    if (dano > 0) {
        for (int i = 0; i < rodadas; i++) {
            vida -= dano;
            if (vida <= 0) {
                break;
            }
        }
    }

    printf("Vida = %d\n", vida);

    // Parte 3 - Recompensa

    float tesouro[7];
    float tesouro_total;

    // Condição para calcular o tesouro e calcular o tesouro
    if (vida > 0 && rodadas > 3) {
        for (int i = 0; i < 7; i++) {
            tesouro[i] = habilidade * (i+1);
            tesouro_total += tesouro[i];
        }

        printf("Soma tesouros = %.2f\n", tesouro_total);

        for (int i = 0; i < 7; i++) {
            printf("%.2f\n", tesouro[i]);
        }
    }

    return 0;
}