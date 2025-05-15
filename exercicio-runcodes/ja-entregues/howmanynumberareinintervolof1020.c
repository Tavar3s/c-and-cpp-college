#include <stdio.h>

int main(void) {
    int n, count = 0, fora = 0;

    scanf("%d", &n);

    int lista[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    for (int i = 0; i < n; i++) {
        if (lista[i] >= 10 && lista[i] <= 20) {
            count++;
        } else {
            fora++;
        }
    }

    printf("%d in\n", count);
    printf("%d out", fora);

    return 0;
}