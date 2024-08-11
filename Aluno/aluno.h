#ifndef ALUNO_H
#define ALUNO_H
#define MAXTAM 100
#define MAXDAY 18
#include "aula.h"
#include "avaliacao.h"

/* Aluno armazenará o nome do aluno, seu número de matrícula, uma lista de aulas com sua presença e a referência para a lista encadeada.*/

typedef struct __Aluno {
    char name[MAXTAM];
    int Mat;
    Aula aula[MAXDAY];
    NotaAluno *notas
    struct __Aluno *prox;
    struct __Aluno *prev;
} Aluno;

typedef struct listaalunos{
    Aluno *cabeca;
}ListaAlunos;

#endif //ALUNO_H
