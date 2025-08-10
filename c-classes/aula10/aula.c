#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str = "Hello, World!";
    char letra = 'a';

    for (int i = 0; i < 13; i++) {
        printf("%c | %d\n", str[i], str[i]);
    }

    printf("%s\n", str);
    printf("%c\n", letra);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    for (int i = 0; i < 255; i++) {
        printf("%d | %c\n", i, (char)i);
    }

    return 0;
}