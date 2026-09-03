#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 50
#define TAM_NOME 30

typedef struct {
    char nome[TAM_NOME];
    int periodo;
    int deadline;
    int burst;
} Tarefa;

int main(int argc, char *argv[]) {
    FILE *arquivo;
    Tarefa tarefas[MAX_TAREFAS];
    int tempo_total;
    int quantidade = 0;
    int i;

    if (argc != 3) {
        printf("Uso: ./scheduler rate|edf arquivo.txt\n");
        return 1;
    }

    printf("Algoritmo escolhido: %s\n", argv[1]);

    arquivo = fopen(argv[2], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de entrada.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &tempo_total);

    while (quantidade < MAX_TAREFAS &&
           fscanf(arquivo, "%s %d %d %d",
                  tarefas[quantidade].nome,
                  &tarefas[quantidade].periodo,
                  &tarefas[quantidade].deadline,
                  &tarefas[quantidade].burst) == 4) {
        quantidade++;
    }

    fclose(arquivo);

    printf("Tempo total: %d\n", tempo_total);
    printf("Tarefas lidas: %d\n", quantidade);

    for (i = 0; i < quantidade; i++) {
        printf("%s P=%d D=%d C=%d\n",
               tarefas[i].nome,
               tarefas[i].periodo,
               tarefas[i].deadline,
               tarefas[i].burst);
    }

    if (strcmp(argv[1], "rate") == 0) {
        printf("Rate-monotonic sera implementado na proxima parte.\n");
    } else if (strcmp(argv[1], "edf") == 0) {
        printf("EDF sera implementado na proxima parte.\n");
    } else {
        printf("Algoritmo desconhecido.\n");
    }

    return 0;
}
