#ifndef SALADEAULA_H
#define SALADEAULA_H

#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"
#include "../Hashing/hashing.h"


typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;
typedef struct __listaavaliacoes ListaAvaliacoes;
typedef struct __listahash ListaHash;

typedef struct saladeaula {
    TabelaHashAluno *alunos;
    ListaAvaliacoes *avaliacoes;
    Aulas aulas;
} SalaDeAula;

SalaDeAula *saladeaula_cria();

void verificaFaltas(Aluno *aluno);

void addFalta(Aluno *aluno, char c);

void cadastraAluno(SalaDeAula *turma);

void cadastraAvaliacao(SalaDeAula *Turma);

void realizaChamada(SalaDeAula *turma);

void relatorioAlunos(SalaDeAula *turma);

void relatorioNotas(SalaDeAula *turma);

#endif
