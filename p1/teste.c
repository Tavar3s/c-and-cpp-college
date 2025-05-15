#include <stdio.h>

int main(void) {
    int a, b;
    float c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%f", &c);

    float d = (a * 0.6 + b * 0.5) * c;
    printf("%f", d);

    return 0;
}