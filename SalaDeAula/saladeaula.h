#ifndef SALADEAULA_H
#define SALADEAULA_H

#include "aluno.h"
#include "presenca.h"
#include "avaliacao.h"

typedef struct saladeaula{
    ListaAlunos * alunos;
    ListaAvaliacoes * avaliacoes;
    Aulas aulas; // ja eh um ponteiro 
}SalaDeAula;


#endif