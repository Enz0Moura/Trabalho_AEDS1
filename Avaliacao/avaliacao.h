#ifndef AVALIACAO_H
#define AVALIACAO_H
#define MAXLEN 100
#include "aluno.h"

/* Avaliação armazenará uma lista de alunos com suas respectivas notas.
* Armazenará o valor total para o cálculo da média do aluno.
* */

typedef struct _notaaluno{
    float nota;
    Aluno *aluno;
} NotaAluno;

typedef struct __avaliacao{
    char nome[MAXLEN];
    floatV valortotal;
    NotaAluno notas[MAXLEN];
    struct __avaliacao *prox;
    struct __avaliacao *ant;
} Avaliacao;

typedef struct __listaavaliacoes{
    Avaliacao *cabeca;
} ListaAvaliacoes;

#endif //AVALIACAO_H
