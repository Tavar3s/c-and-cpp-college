#include <stdio.h>

int main(void) {
    float aluno, count_rec, count_reprov, count_aprov = 0;

    scanf("%f", &aluno);

    if (aluno == 0) {
        return 1;
    }

    float medias[(int)aluno], media_sala;

    for (int i = 0; i < aluno; i++) {
        float nota1, nota2, media;
        scanf("%f %f", &nota1, &nota2);
        media = (nota1 * 4 + nota2 * 6) / 10.0;
        medias[i] = media;
    }

    for (int i = 0; i < aluno; i++) {
        media_sala += medias[i];
    }

    printf("Media da turma: %.2f\n", media_sala / aluno);

    for (int i = 0; i < aluno; i++) {
        printf("%.2f\n", medias[i]);
    }

    for (int i = 0; i < aluno; i++) {
        if (medias[i] >= 5.0) {
            count_aprov++;
        } else if (medias[i] >= 3.0) {
            count_rec++;
        } else {
            count_reprov++;
        }
    }

    printf("Alunos aprovados: %.0f%%\n", (count_aprov/aluno) * 100);
    printf("Alunos em recuperacao: %.0f%%\n", (count_rec/aluno) * 100);
    printf("Alunos reprovados: %.0f%%\n", (count_reprov/aluno) * 100);

    return 0;
}