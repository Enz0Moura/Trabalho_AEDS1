#ifndef SALADEAULA_H
#define SALADEAULA_H

#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"
#include <stdlib.h>

typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;
typedef struct __listaavaliacoes ListaAvaliacoes;

typedef struct saladeaula{
    ListaAlunos * alunos;
    ListaAvaliacoes * avaliacoes;
    Aulas* aulas; // um ponteiro para uma lista de ponteiros. todo: Talvez não esteja bom.
}SalaDeAula;

SalaDeAula* saladeaula_cria(){
      SalaDeAula* nova = (SalaDeAula*)malloc(sizeof(SalaDeAula));
      nova->alunos = NULL;
      nova->avaliacoes = NULL;
      return nova;
};

#endif