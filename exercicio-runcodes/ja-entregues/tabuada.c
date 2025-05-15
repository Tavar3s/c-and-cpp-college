#include <stdio.h>

int main(void) {
    int num, prod = 1;
    int count = 0;

    scanf("%i", &num);

    while (1) {
        prod = num * (count + 1);
        printf("%ix%i=%i\n", num, count+1, prod);
        count = count + 1;
        if (count >= 10) {
            break;
        }
    }

    return 0;
}