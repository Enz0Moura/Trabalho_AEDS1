#ifndef AVALIACAO_H
#define AVALIACAO_H
#define MAXLEN 100
#include "aluno.h"

/* Avaliação armazenará uma lista de alunos com suas respectivas notas.
* Armazenará o valor total para o cálculo da média do aluno.
* */

typedef struct _notaaluno{
    int nota;
    Aluno *aluno;
} NotaAluno;

typedef struct _avaliacao{
    char nome[MAXLEN];
    int valortotal;
    NotaAluno notas[MAXLEN];
} Avaliacao;

#endif //AVALIACAO_H
