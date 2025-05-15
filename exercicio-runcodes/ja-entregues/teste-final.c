#include <stdio.h>

// O erro era o tipo que usei, double, pq queria mais precisão
int main(void) {
    float valor_entrada, rentabilidade;

    scanf("%f", &valor_entrada);
    scanf("%f", &rentabilidade);

    float valor_rend1 = valor_entrada * (rentabilidade/100);
    float imposto1= valor_rend1 * 0.2500;
    valor_entrada += valor_rend1 - imposto1;
    printf("%.2f\n", valor_entrada);

    float valor_rend2 = valor_entrada * (rentabilidade/100);
    float imposto2= valor_rend2 * 0.22;
    valor_entrada += valor_rend2 - imposto2;
    printf("%.2f\n", valor_entrada);

    float valor_rend3 = valor_entrada * (rentabilidade/100);
    float imposto3= valor_rend3 * 0.20;
    valor_entrada += valor_rend3 - imposto3;
    printf("%.2f\n", valor_entrada);

    return 0;
}