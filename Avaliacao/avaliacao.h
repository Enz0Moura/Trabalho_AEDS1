#ifndef AVALIACAO_H
#define AVALIACAO_H
#define MAXLEN 100
#include "../Aluno/aluno.h"
#include <stdlib.h>
#include <stdio.h>

/* Avaliação armazenará uma lista de alunos com suas respectivas notas.
* Armazenará o valor total para o cálculo da média do aluno.
* */
typedef struct __Aluno Aluno;

typedef struct _notaaluno {
    float nota;
    Aluno *aluno;
} NotaAluno;

typedef struct __avaliacao {
    char nome[MAXLEN];
    float valortotal;
    NotaAluno *notas[MAXLEN];
    struct __avaliacao *prox;
} Avaliacao;

typedef struct __listaavaliacoes {
    Avaliacao *cabeca;
} ListaAvaliacoes;

ListaAvaliacoes *listaAvaliacoes_cria();

#endif //AVALIACAO_H
