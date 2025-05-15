#include <stdio.h>

int main(void) {
    float teste = 0;

    scanf("%f", &teste);

    if (teste >= 0 && teste <= 25) {
        printf("Intervalo [0,25]\n");
    } else if (teste > 25 && teste <= 50) {
        printf("Intervalo (25,50]\n");
    } else if (teste > 50 && teste <= 75) {
        printf("Intervalo (50,75]\n");
    } else if (teste > 75 && teste <= 100) {
        printf("Intervalo (75,100]\n");
    } else {
        printf("Fora de intervalo\n");
    }

    return 0;
}