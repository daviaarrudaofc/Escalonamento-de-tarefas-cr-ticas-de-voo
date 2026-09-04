#include <stdio.h>
#include <string.h>

#define MAX_TAREFAS 50
#define TAM_NOME 30

typedef struct {
    char nome[TAM_NOME];
    int periodo;
    int deadline;
    int burst;
    int restante;
    int completas;
    int perdidas;
    int mortas;
} Tarefa;

int algoritmo_valido(char algoritmo[]) {
    if (strcmp(algoritmo, "rate") == 0) {
        return 1;
    }

    if (strcmp(algoritmo, "edf") == 0) {
        return 1;
    }

    return 0;
}

void montar_nome_saida(char algoritmo[], char login[], char nome_saida[]) {
    sprintf(nome_saida, "%s_%s.out", algoritmo, login);
}

void gravar_saida_inicial(char algoritmo[], char login[], int tempo_total, Tarefa tarefas[], int quantidade) {
    FILE *saida;
    char nome_saida[40];
    int i;

    montar_nome_saida(algoritmo, login, nome_saida);

    saida = fopen(nome_saida, "w");
    if (saida == NULL) {
        fprintf(stderr, "Erro ao criar arquivo de saida.\n");
        return;
    }

    if (strcmp(algoritmo, "rate") == 0) {
        fprintf(saida, "EXECUTION BY RATE\n");
    } else {
        fprintf(saida, "EXECUTION BY EDF\n");
    }

    fprintf(saida, "READ INPUT\n");
    fprintf(saida, "total time %d\n", tempo_total);

    for (i = 0; i < quantidade; i++) {
        fprintf(saida, "[%s] period=%d deadline=%d burst=%d\n",
                tarefas[i].nome,
                tarefas[i].periodo,
                tarefas[i].deadline,
                tarefas[i].burst);
    }

    fprintf(saida, "LOST DEADLINES\n");
    for (i = 0; i < quantidade; i++) {
        fprintf(saida, "[%s] %d\n", tarefas[i].nome, tarefas[i].perdidas);
    }

    fprintf(saida, "COMPLETE EXECUTION\n");
    for (i = 0; i < quantidade; i++) {
        fprintf(saida, "[%s] %d\n", tarefas[i].nome, tarefas[i].completas);
    }

    fprintf(saida, "KILLED\n");
    for (i = 0; i < quantidade; i++) {
        fprintf(saida, "[%s] %d\n", tarefas[i].nome, tarefas[i].mortas);
    }

    fclose(saida);
}

int main(int argc, char *argv[]) {
    FILE *arquivo;
    Tarefa tarefas[MAX_TAREFAS];
    char login[] = "dab";
    int tempo_total;
    int quantidade = 0;

    if (argc != 3) {
        fprintf(stderr, "Uso: ./scheduler rate|edf arquivo.txt\n");
        return 1;
    }

    if (!algoritmo_valido(argv[1])) {
        fprintf(stderr, "Erro: algoritmo invalido. Use rate ou edf.\n");
        return 1;
    }

    arquivo = fopen(argv[2], "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo de entrada.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &tempo_total);

    while (quantidade < MAX_TAREFAS &&
           fscanf(arquivo, "%s %d %d %d",
                  tarefas[quantidade].nome,
                  &tarefas[quantidade].periodo,
                  &tarefas[quantidade].deadline,
                  &tarefas[quantidade].burst) == 4) {
        tarefas[quantidade].restante = tarefas[quantidade].burst;
        tarefas[quantidade].completas = 0;
        tarefas[quantidade].perdidas = 0;
        tarefas[quantidade].mortas = 0;
        quantidade++;
    }

    fclose(arquivo);

    gravar_saida_inicial(argv[1], login, tempo_total, tarefas, quantidade);

    return 0;
}
