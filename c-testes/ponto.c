#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

 typedef struct ponto {
    double x;
    double y;
};

Ponto* ponto_cria(double x, double y) {
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void ponto_libera(Ponto* p) {
    free(p);
}

void acessa_ponto(Ponto* p, double* x, double* y) {
    if (p != NULL) {
        *x = p->x;
        *y = p->y;
    }
}

void atribui_ponto(Ponto* p, double x, double y) {
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
}

float ponto_distancia(Ponto* p1, Ponto* p2) {
    if (p1 == NULL || p2 == NULL) return -1.0f; // Retorna -1 se algum ponto for nulo
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    return (float)sqrt(dx * dx + dy * dy);
}
