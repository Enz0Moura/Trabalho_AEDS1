#ifndef SALADEAULA_H
#define SALADEAULA_H
#include <stdlib.h>
#include <stdio.h>
#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"
#include "../utils/utils.h"

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
    remove_newline(novo->name);

    printf("\nDigite o Curso do aluno: ");
    fgets(novo->curso, MAXTAM, stdin);
    remove_newline(novo->curso);

    printf("\nDigite a matricula: ");
    scanf("%d", &(novo->Mat));
    flush_in();

    printf("\nDigite o ano de entrada do aluno: ");
    scanf("%d", &(novo->anoEntrada));
    flush_in();


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
            flush_in();
            while (aux != 'P' && aux != 'F') {
                printf("\nA presenca deve ser P ou F, digite novamente!");
                scanf("%c", &aux);
                flush_in();
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
        NotaAluno *notaAux;

        while (aux != NULL) {
            printf("Digite a nota de %s na avalicao %s: ", novo->name, aux->nome);
            scanf("%f", &nota);
            flush_in();

            int indice = 0;
            while (aux->notas[indice] != NULL) {
                indice++;
            }
            notaAux = (NotaAluno *) malloc(sizeof(NotaAluno));
            notaAux->aluno = novo;
            notaAux->nota = nota;
            aux->notas[indice] = notaAux;
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
    remove_newline(nova->nome);

    printf("Digite o valor total da avaliacao: ");
    scanf("%f", &nova->valortotal);
    flush_in();
    // colocando a nota de cada aluno na avaliacao
    Aluno *alAux = Turma->alunos->cabeca;
    float nota;
    NotaAluno *notaAux;
    int indice = -1;

    while (alAux != NULL) {
        indice++;
        printf("Digite a nota do aluno %s: ", alAux->name);
        scanf("%f", &nota);
        flush_in();
        notaAux = (NotaAluno *) malloc(sizeof(NotaAluno));
        notaAux->aluno = alAux;
        notaAux->nota = nota;
        nova->notas[indice] = notaAux;
        alAux = alAux->prox;
    }

    while (aux != NULL && aux->prox != NULL) {
        aux = aux->prox;
    }
    if (aux == NULL) {
        Turma->avaliacoes->cabeca = nova;
        return;
    }
    aux->prox = nova; // se ja tiverem avaliacoes cadastradas
    return;
}

#endif
