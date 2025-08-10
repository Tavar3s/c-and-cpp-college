#include <stdio.h>

int max(int a[6], int n) {
    int i, max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;

}

int main(void) {
    int a[6] = {5, 20, 30, 15, 23, 6};

    printf("O maior elemento do array é: %d\n", max(a, 6)); // Passa o array e o tamanho do array para a função max
    
    return 0;
}