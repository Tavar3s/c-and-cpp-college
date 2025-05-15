#include <stdio.h>


int main() {
    double valor_investido, rentabilidade;

    scanf("%lf", &valor_investido);
    scanf("%lf", &rentabilidade);

    double rendimento_mes1 = valor_investido * rentabilidade/100;
    double imposto1 = rendimento_mes1 * 0.25;
    double valor_liquido = valor_investido + rendimento_mes1 - imposto1;
    printf("%.2f\n", valor_liquido);

    double imposto2 = rendimento_mes1 * 0.22;
    valor_liquido = valor_investido + rendimento_mes1 - imposto2;
    printf("%.2f\n", valor_liquido);

    double imposto3 = rendimento_mes1 * 0.2;
    valor_liquido = valor_investido + rendimento_mes1 - imposto3;
    printf("%.2f\n", valor_liquido);

    return 0;
}