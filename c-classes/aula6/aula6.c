#include <stdio.h>

void troca(int *a, int *b) { // O * indica que a função recebe as variáveis, não os valores
    
    int temp = *a;
    *a = *b;
    *b = temp;

}

int main(void) {
    int a, b;
    
    scanf("%d %d", &a, &b);

    printf("Antes da troca: a = %d, b = %d\n", a, b);

    troca(&a, &b); // Passa o endereço das variáveis a e b para a função troca

    printf("Depois da troca: a = %d, b = %d\n", a, b);

    return 0;
}
