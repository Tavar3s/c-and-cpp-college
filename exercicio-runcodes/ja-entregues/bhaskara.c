#include <stdio.h>
#include <math.h>

int main(void) {
    double a, b, c, delta, x1, x2;

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    delta = b * b - 4 * a * c;

    if (a == 0  || delta < 0) {
        printf("Impossivel calcular\n");
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("R1 = %.5lf\n", x1);
        printf("R2 = %.5lf\n", x2);
    }

    return 0;
}