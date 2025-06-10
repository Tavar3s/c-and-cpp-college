#include <stdio.h>

// retorno nome(parâmetros) {} <-- função

int main(void) {
    float num1, num2;
    int operacao;

    printf("Digite os número: ");
    scanf("%f", &num1);
    scanf("%f", &num2);

    while (1){
        printf("Operações disponíveis:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Sair\n");
        printf("Escolha a operação desejada: ");

        scanf("%d", &operacao);

        switch (operacao) {
            case 1:
                printf("Resultado: %.2f\n", num1 + num2);
                break;
            case 2:
                printf("Resultado: %.2f\n", num1 - num2);
                break;
            case 3:
                printf("Resultado: %.2f\n", num1 * num2);
                break;
            case 4:
                if (num2 != 0) {
                    printf("Resultado: %.2f\n", num1 / num2);
                } else {
                    printf("Erro: Divisão por zero não é permitida.\n");
                }
                break;
            case 5:
                printf("Programa encerrado.\n");
                return 0;
            default:
                printf("Operação inválida.\n");
        }
    }
    
    return 0;
}