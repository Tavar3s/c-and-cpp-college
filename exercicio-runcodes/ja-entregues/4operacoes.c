#include <stdio.h>

//Feito
int main() {
    long num1, num2, num3;

    scanf("%ld", &num1);
    scanf("%ld", &num2);
    scanf("%ld", &num3);

    long num_cubo = num1 * num1 * num1;
    float divisao = (float)num2 / num1;
    long operacao_and = num2 & num3;
    long negacao = ~num3;

    printf("%ld\n", num_cubo);
    printf("%.2f\n", divisao);
    printf("%ld\n", operacao_and);
    printf("%ld\n", negacao);

    return 0;
}