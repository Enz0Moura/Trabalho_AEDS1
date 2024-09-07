#ifndef SALADEAULA_H
#define SALADEAULA_H
#include <stdlib.h>
#include <stdio.h>
#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"

typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;
typedef struct __listaavaliacoes ListaAvaliacoes;

typedef struct saladeaula {
    ListaAlunos *alunos;
    ListaAvaliacoes *avaliacoes;
    Aulas aulas;
} SalaDeAula;

SalaDeAula *saladeaula_cria() {
    SalaDeAula *nova = (SalaDeAula *) malloc(sizeof(SalaDeAula));
    nova->alunos = listaAlunos_cria();
    nova->avaliacoes = listaAvaliacoes_cria();
    for (int i = 0; i < MAX_AULAS; i++) {
        nova->aulas[i] = NULL;
    };
    return nova;
};

void cadastraAluno(SalaDeAula *turma) {
    printf("+=-=-=-=-=-=-=-=-=+\n");
    printf("|CADASTRE UM ALUNO|");
    printf("\n+=-=-=-=-=-=-=-=-=+\n");

    Aluno *novo = (Aluno *) malloc(sizeof(Aluno));
    novo->prox = NULL;

    printf("Digite o nome do aluno: ");
    fgets(novo->name, MAXTAM, stdin);

    printf("\nDigite o Curso do aluno: ");
    fgets(novo->curso, MAXTAM, stdin);

    printf("\nDigite a matricula: ");
    scanf("%d", &(novo->Mat));

    printf("\nDigite o ano de entrada do aluno: ");
    scanf("%d", &(novo->anoEntrada));

    // colocando o aluno na lista de alunos da turma

    if (turma->alunos->cabeca == NULL) {
        turma->alunos->cabeca = novo;
    } else {
        Aluno *auxiliar = turma->alunos->fim;
        auxiliar->prox = novo;
    }
    turma->alunos->fim = novo;

    if (turma->aulas[0] != NULL) {
        char aux;
        int i = 0;
        while (i < MAX_AULAS && turma->aulas[i] != NULL) {
            printf("\nPresenca do aluno no dia %d (P/F): ", turma->aulas[i]->dia);
            scanf("%c", &aux);
            while (aux != 'P' && aux != 'F') {
                printf("\nA presenca deve ser P ou F, digite novamente!");
                scanf("%c", &aux);
            }
            bool foi = aux == 'P' ? true : false; // se foi retorna true se nao retorna false
            Presenca *hj = turma->aulas[i]->cabeca;
            while (hj->prox != NULL) {
                hj = hj->prox;
            }
            Presenca *nova = (Presenca *) malloc(sizeof(Presenca));
            nova->aluno = novo;
            nova->foi = foi;
            nova->prox = NULL;

            hj->prox = nova;
            i++;
        }
    }

    if (turma->avaliacoes != NULL) {
        Avaliacao *aux = turma->avaliacoes->cabeca;
        float nota;
        while (aux != NULL) {
            printf("Digite a nota do aluno na avalicao %s", aux->nome);
            scanf("%f", &nota);
            int indice = 0;
            while (aux->notas[indice] != NULL) {
                indice++;
            }
            aux->notas[indice]->nota = nota;
            aux->notas[indice]->aluno = novo;

            aux = aux->prox;
        }
    }
}

void cadastraAvaliacao(SalaDeAula *Turma) {
    Avaliacao *aux = Turma->avaliacoes->cabeca;
    Avaliacao *nova = (Avaliacao *) malloc(sizeof(Avaliacao));

    nova->prox = NULL;

    printf("Digite o nome da avaliacao: ");
    fgets(nova->nome, MAXLEN, stdin);

    printf("Digite o valor total da avaliacao: ");
    scanf("%f", &nova->valortotal);

    // colocando a nota de cada aluno na avaliacao
    Aluno *alAux = Turma->alunos->cabeca;
    float nota;
    int indice = 0;
    while (alAux != NULL) {
        printf("Digite a nota do aluno %s: ", alAux->name);
        scanf("%f", &nota);
        nova->notas[indice]->aluno = alAux;
        nova->notas[indice]->nota = nota;
        indice++;
    }

    while (aux != NULL && aux->prox != NULL) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        // se for a primeira avaliacao
        aux = nova;
        return;
    }
    aux->prox = nova; // se ja tiverem avaliacoes cadastradas
}

#endif
