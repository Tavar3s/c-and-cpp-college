#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

// Pra rodar: gcc main.c Ponto.c -o output\programa.exe 
//            .\output\programa.exe

/*
    Observações:
    Para rodar um arquivo modularizado por aqui, no terminal se deve compilar todos os arquivos .c relacionados.
    Exemplo: gcc main.c Ponto.c -o output\programa.exe

*/

int main() {
    // Criação de dois pontos
    Ponto* p1 = ponto_cria(3.0, 4.0);
    Ponto* p2 = ponto_cria(6.0, 8.0);

    // Acessando coordenadas dos pontos
    double x1, y1, x2, y2;
    acessa_ponto(p1, &x1, &y1);
    acessa_ponto(p2, &x2, &y2);
    printf("Ponto 1: (%.2f, %.2f)\n", x1, y1);
    printf("Ponto 2: (%.2f, %.2f)\n", x2, y2);

    // Calculando a distância entre os pontos
    float distancia = ponto_distancia(p1, p2);
    printf("Distância entre os pontos: %.2f\n", distancia);

    // Liberando memória
    ponto_libera(p1);
    ponto_libera(p2);

    return 0;
}