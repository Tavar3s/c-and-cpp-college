#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned short hora;
    unsigned short minuto;
    unsigned short segundo;
} Hora;

typedef struct {
    char nome[35];
    char unidade[8];
    double valor;
    Hora time_value;
    unsigned int porta;
} Sensor;

// Função para ler string com segurança
void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove o \n
}

// Cria um novo sensor
Sensor novoSensor() {
    Sensor s;
    lerString(s.nome, sizeof(s.nome));
    lerString(s.unidade, sizeof(s.unidade));
    scanf("%lf", &s.valor);
    scanf("%hu %hu %hu", &s.time_value.hora, &s.time_value.minuto, &s.time_value.segundo);
    scanf("%u", &s.porta);
    getchar(); // Limpa o \n restante do buffer

    return s;
}

// Lista todos os sensores
void listarSensores(Sensor* sensores, size_t total) {
    if (total == 0) {
        printf("Nenhum sensor cadastrado.\n");
        return;
    }

    for (size_t i = 0; i < total; i++) {
        printf("\nSensor %zu:\n", i + 1);
        printf("  Nome: %s\n", sensores[i].nome);
        printf("  Unidade: %s\n", sensores[i].unidade);
        printf("  Valor: %.2lf\n", sensores[i].valor);
        printf("  Hora: %02hu:%02hu:%02hu\n",
               sensores[i].time_value.hora,
               sensores[i].time_value.minuto,
               sensores[i].time_value.segundo);
        printf("  Porta: %u\n", sensores[i].porta);
    }
}

// Grava sensores em arquivo
void salvarSensores(const char* nomeArquivo, Sensor* sensores, size_t total) {
    FILE* arq = fopen(nomeArquivo, "wb");
    if (!arq) {
        printf("Erro ao criar arquivo.\n");
        return;
    }

    fwrite(&total, sizeof(size_t), 1, arq);
    fwrite(sensores, sizeof(Sensor), total, arq);
    fclose(arq);

    printf("Sensores salvos em '%s'.\n", nomeArquivo);
}

// Recupera sensores de um arquivo
Sensor* carregarSensores(const char* nomeArquivo, size_t* total) {
    FILE* arq = fopen(nomeArquivo, "rb");
    if (!arq) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    fread(total, sizeof(size_t), 1, arq);
    Sensor* sensores = (Sensor*) malloc((*total) * sizeof(Sensor));
    if (!sensores) {
        fclose(arq);
        printf("Erro de memória.\n");
        return NULL;
    }

    fread(sensores, sizeof(Sensor), *total, arq);
    fclose(arq);

    printf("%zu sensores carregados de '%s'.\n", *total, nomeArquivo);
    return sensores;
}

int main() {
    Sensor* sensores = NULL;
    size_t total = 0;
    int opcao;
    char nomeArquivo[50];

    do {
        printf("\n==== MENU ====\n");
        printf("1. Cadastrar novo sensor\n");
        printf("2. Listar sensores\n");
        printf("3. Guardar sensores no arquivo\n");
        printf("4. Recuperar sensores do arquivo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar \n

        switch (opcao) {
            case 1: {
                Sensor novo = novoSensor();
                Sensor* temp = realloc(sensores, (total + 1) * sizeof(Sensor));
                if (temp == NULL) {
                    printf("Erro de alocação de memória.\n");
                } else {
                    sensores = temp;
                    sensores[total++] = novo;
                }
                break;
            }
            case 2:
                listarSensores(sensores, total);
                break;
            case 3:
                lerString(nomeArquivo, sizeof(nomeArquivo));
                salvarSensores(nomeArquivo, sensores, total);
                break;
            case 4:
                lerString(nomeArquivo, sizeof(nomeArquivo));
                free(sensores);
                sensores = carregarSensores(nomeArquivo, &total);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    free(sensores);
    return 0;
}