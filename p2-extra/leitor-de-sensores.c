#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned short hora;
    unsigned short minuto;
    unsigned short segundo;
} Hora;


typedef struct {
    char nome[35];           // Nome do sensor
    char unidade[8];        // Unidade de medida (C, Pa, etc.)
    double valor;            // Último valor medido
    Hora time_value;         // Horário da última medição
    unsigned int porta;      // Porta de conexão
} Sensor;

Sensor novoSensor() {
/* Funcao que pede ao usuario para entrar com informacoes
 * sobre um sensor e retorna essa variavel
 */
    Sensor s;
    scanf("%[^\n]", s.nome);
    scanf("%7s", s.unidade);
    scanf("%lf", &s.valor);
    scanf("%02hu %02hu %02hu", &s.time_value.hora, &s.time_value.minuto, &s.time_value.segundo);
    scanf("%u", &s.porta);

    return s;
}

void listarSensores(Sensor* sensores, size_t total) {
/* Lista os sensores atualmente cadastrados no array sensores
 * Parametros:
 * 	Sensor* sensores - array de sensores
 *	size_t total - variavel contendo o total de sensores cadastrados
 */
    if (total == 0) {
        printf("Nenhum sensor cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nSensor %d:\n", i + 1);
        printf("  Nome: %s\n", sensores[i].nome);
        printf("  Unidade: %s\n", sensores[i].unidade);
        printf("  Valor: %.2f\n", sensores[i].valor);
        printf("  Hora: %02hu:%02hu:%02hu\n",
               sensores[i].time_value.hora,
               sensores[i].time_value.minuto,
               sensores[i].time_value.segundo);
        printf("  Porta: %u\n", sensores[i].porta);
    }
}

int main() {
    Sensor* sensores = NULL;
    size_t total = 0;
    char filename[64];
    int opcao;

    do {
        printf("\n==== MENU ====\n");
        printf("1. Cadastrar novo sensor\n");
        printf("2. Listar sensores\n");
        printf("3. Guardar sensores no arquivo\n");
        printf("4. Recuperar sensores do arquivo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
	getchar();

        switch (opcao) {
            case 1: {
                // Realiza o realocamento da memória e adiciona um novo sensor. Condicional para validaçao de memória
                total++;
                sensores = realloc(sensores, total * sizeof(Sensor));
                if (sensores == NULL) {
                    fprintf(stderr, "Erro ao alocar memória para sensores.\n");
                    return 1;
                }
                sensores[total - 1] = novoSensor();
                break;
            }
            case 2:
                // Lista os sensores cadastrados
                listarSensores(sensores, total);
		        break;
            case 3:
                fgets(filename, 64, stdin);
                fwrite(&total, sizeof(size_t), 1, filename);

                // guarda sensores em arquivo
                break;
            case 4:
                // recupera sensores de arquivo
                scanf("%[^\n]", filename);
                FILE* arquivo = fopen(filename, "rb");
                if (arquivo == NULL) {
                    printf("Erro ao abrir arquivo\n");
                    break;
                }
                sensores = realloc(sensores, total * sizeof(Sensor));
                int count;
                fread(&total, sizeof(size_t), 1, arquivo);
                
                if (sensores == NULL) {
                    fprintf(stderr, "Erro ao alocar memória para sensores.\n");
                    return 1;
                }

                printf("%zu sensores carregados de %s\n", total, filename);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);


    if (sensores != NULL) {
    	free(sensores);
    }

    return 0;
}
// Fim do arquivo leitor-de-sensores.c