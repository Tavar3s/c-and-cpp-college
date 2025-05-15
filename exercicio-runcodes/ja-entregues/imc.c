#include <stdio.h>

int main(void) {
    float peso1, altura1, imc1;
    float peso2, altura2, imc2;

    scanf("%f %f", &peso1, &altura1);
    scanf("%f %f", &peso2, &altura2);

    imc1 = peso1 / (altura1 * altura1);
    imc2 = peso2 / (altura2 * altura2);

    if (imc1 > imc2) {
        printf("1");
    } else if (imc1 < imc2) {
        printf("2");
    } else {
        printf("0");
    }

    return 0;
}