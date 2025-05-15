#include <stdio.h>

int main(void) {
    int num1, num2, num3, maior = 0;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    if (num1 > maior) {
        maior = num1;
    }
    if (num2 > maior) {
        maior = num2;
    }
    if (num3 > maior) {
        maior = num3;
    }

    printf("%d", maior);
    printf(" eh o maior");
    
    return 0;
}