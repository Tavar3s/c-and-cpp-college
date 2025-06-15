#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main() {
    struct Pessoa *banco_de_dados = NULL;
    int capacidade = 0, total = 0;
    int opcao;

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Adicionar Pessoa\n");
        printf("2 - Listar Pessoas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total == capacidade) {
                capacidade = capacidade == 0 ? 2 : capacidade * 2; // condição ? valor se verdadeiro : valor se falso
                banco_de_dados = realloc(banco_de_dados, capacidade * sizeof(struct Pessoa));
                if (!banco_de_dados) {
                    printf("Erro de memoria!\n");
                    exit(1);
                }
            }
            printf("Digite o nome: ");
            scanf("%49s", banco_de_dados[total].nome);
            printf("Digite a idade: ");
            scanf("%d", &banco_de_dados[total].idade);
            printf("Digite a altura: ");
            scanf("%f", &banco_de_dados[total].altura);
            total++;
        } else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhuma pessoa cadastrada.\n");
            } else {
                for (int i = 0; i < total; i++) {
                    printf("\nPessoa %d: ", i + 1);
                    printf("Nome: %s ", banco_de_dados[i].nome);
                    printf("Idade: %d ", banco_de_dados[i].idade);
                    printf("Altura: %.2f\n", banco_de_dados[i].altura);
                }
            }
        } else if (opcao == 0) {
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }

    for (int i = 0; i < total; i++) {
        memset(banco_de_dados[i].nome, 0, sizeof(banco_de_dados[i].nome));
        banco_de_dados[i].altura = 0.0f;
        banco_de_dados[i].idade = 0;
    }

    free(banco_de_dados);
    banco_de_dados = NULL;
    printf("Programa encerrado.\n");
    
    return 0;
}