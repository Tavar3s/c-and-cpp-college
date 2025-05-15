#include <stdio.h>

int main(void) {
    float a, b, c;

    while (1) {
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);

        if ((a + b > c) && (a + c > b) && (b + c > a)) {
            
        } else {
            printf("Os segmentos de reta nao podem formar um triangulo");
            break;
        }
    }
    
    return 0;
}