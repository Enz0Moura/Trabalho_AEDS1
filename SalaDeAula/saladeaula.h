#ifndef SALADEAULA_H
#define SALADEAULA_H

#include "../Aluno/aluno.h"
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"

typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;
typedef struct __listaavaliacoes ListaAvaliacoes;

typedef struct saladeaula{
    ListaAlunos * alunos;
    ListaAvaliacoes * avaliacoes;
    Aulas aulas; // ja eh um ponteiro 
}SalaDeAula;

SalaDeAula* saladeaula_cria(){
      SalaDeAula* nova = (SalaDeAula*)malloc(sizeof(SalaDeAula));
      nova->alunos = NULL;
      nova->avaliacoes = NULL;
      return nova;
};

#endif