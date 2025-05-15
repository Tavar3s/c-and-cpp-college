#include <stdio.h>

void piramide(int n) {
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < i; j++){
            printf("!");
        }
        printf("\n");
    }
}

int main(){
    int quantas_vezes_roda;

    scanf("%d", &quantas_vezes_roda);

    piramide(quantas_vezes_roda);

}