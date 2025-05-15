#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;
    if (n == 0) {
        return;
    }

    if (n == 1) {
        printf("%d ", a);
        return;
    }

    printf("%d ", a);
    printf("%d ", b);
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main(void) {
    int n;

    scanf("%d", &n);
    fibonacci(n);

    return 0;
}