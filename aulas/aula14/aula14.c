#include <stdio.h>

/*  Observações: pela configuração do IDE, para inserir valores na main
    Precisar executar e colocar os valores ao msm tempo: ./arq.c prog 12 edef 23 etc
    Tbm, ao ter o nome do arq para fopen e demais usar ../ antes, porque o executável 
    é criado dentro do output  */

// Imprime um menu com o texto fornecido
void imprime_menu(char* texto) {
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%s\n", texto);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

// Insere um aluno no arquivo com o nome e idade fornecidos
void inserir_aluno(FILE *arq, char *nome, int idade) {
    fputs(nome, arq);
    fputs(" ", arq);
    fprintf(arq, "%d", idade);
    fputs("\n", arq);
}

// Função principal do programa
int main() {
    // Declaração de variáveis
    FILE *arq;
    int num_alunos, opcao;
    char* arq_nome = "../alunos.txt";

    // Abrindo e verificando o arquivo
    arq = fopen(arq_nome, "a");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arq_nome);
        return 1;
    } else {
        imprime_menu("Arquivo aberto com sucesso!");
    }
    
    // Loop principal do programa
    while (1) {
        // OCndicional para executar as opções de interação
        printf("Opções de interação:\n 1 - Inserir alunos\n 2 - visualizar nomes\n 0 - Sair\nInsira a opção desejada: ");
        scanf("%d", &opcao);
        if (opcao == 0) {
            imprime_menu("Saindo do programa...");
            break;
        } else if (opcao != 1 && opcao != 2) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        } else if (opcao == 1) {
            // Opção que insere alunos
            imprime_menu("Quantidade de alunos a inserir: ");
            scanf("%d", &num_alunos);
            for (int i = 0; i < num_alunos; i++) {
                char nome[50];
                int idade;

                printf("Digite o nome do aluno %d: ", i + 1);
                scanf("%s", nome);
                printf("Digite a idade do aluno %d: ", i + 1);
                scanf("%d", &idade);

                inserir_aluno(arq, nome, idade);
            }
        } else if (opcao == 2) {
            // Opção que visualiza os nomes dos alunos
            imprime_menu("Visualizando nomes dos alunos:");
            fclose(arq);
            arq = fopen(arq_nome, "r");
            if (arq == NULL) {
                printf("Erro ao abrir o arquivo %s para leitura\n", arq_nome);
                return 1;
            }
            char linha[100];
            while (fgets(linha, sizeof(linha), arq)) {
                printf("%s", linha);
            }
            fclose(arq);
            arq = fopen(arq_nome, "a"); // Reabre o arquivo para escrita
        }
        
    }

    // Fechando o arquivo e finalizando o programa
    fclose(arq);
    return 0;
}