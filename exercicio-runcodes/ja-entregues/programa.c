#include <stdio.h>

// Feito
int main(){
    double valor_entrada, rend_mensal;

    scanf("%lf", &valor_entrada);
    scanf("%lf", &rend_mensal);

    double rendimento1 = valor_entrada * rend_mensal/100;
    double imposto1 = rendimento1 * 0.25;
    valor_entrada = valor_entrada + (rendimento1-imposto1);
    printf("\n%.2f\n", valor_entrada);

    double rendimento2 = valor_entrada * rend_mensal/100;
    double imposto2 = rendimento2 * 0.22;
    valor_entrada = valor_entrada + (rendimento2 - imposto2);
    printf("%.2f\n", valor_entrada);

    double rendimento3 = valor_entrada * rend_mensal/100;
    double imposto3 = rendimento3 * 0.2;
    valor_entrada = valor_entrada + (rendimento3 - imposto3);
    printf("%.2f\n\n", valor_entrada);

    return 0;
}