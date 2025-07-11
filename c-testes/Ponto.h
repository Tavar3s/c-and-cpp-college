typedef struct ponto Ponto;

Ponto* ponto_cria(double x, double y);
void ponto_libera(Ponto* p);
void acessa_ponto(Ponto* p, double* x, double* y);
void atribui_ponto(Ponto* p, double x, double y);
float ponto_distancia(Ponto* p1, Ponto* p2);