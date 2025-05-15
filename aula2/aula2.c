#include <stdio.h>

//Uso do void é dado por segurança, pois não é necessário passar argumentos para a função main
int main(void) {
    int cont_view;

    scanf("%d", &cont_view);

    if (cont_view < 100) {
        cont_view += 1;        
    }
    

    printf("Visualizações: %d\n", cont_view);


    printf("Visualizações: %d\n", cont_view);

    return 0;
}
