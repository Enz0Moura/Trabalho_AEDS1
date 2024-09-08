#ifndef SALADEAULA_H
#define SALADEAULA_H
#include <stdlib.h>
#include <stdio.h>
#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"
#include "../utils/utils.h"
#include "../Hashing/hashing.h"

typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;
typedef struct __listaavaliacoes ListaAvaliacoes;
typedef struct __presenca Presenca;
typedef struct __dia Dia;


typedef struct saladeaula {
    TabelaHashAluno *alunos;
    ListaAvaliacoes *avaliacoes;
    Aulas aulas;
} SalaDeAula;

SalaDeAula *saladeaula_cria() {
    SalaDeAula *nova = (SalaDeAula *) malloc(sizeof(SalaDeAula));
    nova->alunos = cria_tabela_hash_aluno();
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
    novo->qtdeFaltas = 0;

    printf("Digite o nome do aluno: ");
    fgets(novo->name, MAXTAM, stdin);
    remove_newline(novo->name);

    printf("\nDigite o Curso do aluno: ");
    fgets(novo->curso, MAXTAM, stdin);
    remove_newline(novo->curso);

    printf("\nDigite o ano de entrada do aluno: ");
    scanf("%d", &(novo->anoEntrada));
    flush_in();

    gerar_matricula(novo);

    // colocando o aluno na lista de alunos da turma

    insere_tabela_aluno(turma->alunos, novo);

    if (turma->aulas[0] != NULL) {
        char aux;
        int i = 0;
        while (i < MAX_AULAS && turma->aulas[i] != NULL) {
            printf("\nDigite a presenca de %s no dia %d (P/F): ", novo->name, turma->aulas[i]->dia);
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
    float nota;
    NotaAluno *notaAux;
    Aluno *alAux;
    int indice = -1;
    for (int i = 0; i < TABLE_SIZE; i++) {
        alAux = Turma->alunos->tabela[i]->cabeca;
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


//todo dps da implementacao da qtdeFaltas fazer a verificacao
//se qtdeFaltas chegar a 10 printar aviso de reprovacao por falta
void realizaChamada(SalaDeAula *turma) {
    int data;

    printf("\nDigite a data da aula: ");
    scanf("%d", &data);
    flush_in();

    int i = 0;
    Dia *auxiliar = criaDia();
    while (turma->aulas[i] != NULL) {
        i++;
    }

    turma->aulas[i] = auxiliar;
    auxiliar->dia = data;
    Aluno *alAux;
    char c;
    for (int j = 0; j < TABLE_SIZE; j++) {
        alAux = turma->alunos->tabela[i]->cabeca;
        while (alAux != NULL) {
            // fazendo para o primeiro cara
            printf("Marque a presenca do aluno %s (P/F)", alAux->name);
            scanf("%c", &c);
            flush_in();
            while (c != 'P' && c != 'F') {
                printf("\nA presenca deve ser P ou F, digite novamente!");
                scanf("%c", &c);
                flush_in();
            }
            Presenca *auxPre = criaPresenca(alAux, c);
            auxiliar->cabeca = auxPre;
            alAux = alAux->prox;
            while (alAux != NULL) {
                printf("Marque a presenca do aluno %s (P/F)", alAux->name);
                scanf("%c", &c);
                flush_in();
                while (c != 'P' && c != 'F') {
                    printf("\nA presenca deve ser P ou F, digite novamente!");
                    scanf("%c", &c);
                    flush_in();
                }
                auxPre->prox = criaPresenca(alAux, c);
                auxPre = auxPre->prox;
                alAux = alAux->prox;
            }
        }
    }
}


#endif
