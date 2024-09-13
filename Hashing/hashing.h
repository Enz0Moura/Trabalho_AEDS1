//
// Created by enzo-moura on 9/8/24.
//

#ifndef HASHING_H
#define HASHING_H

#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"

#define TABLE_SIZE 100


typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;

typedef struct __tabelaHashAluno {
    ListaAlunos *tabela[TABLE_SIZE];
    int indices_validos[TABLE_SIZE];
    int contador_indices;
} TabelaHashAluno;

TabelaHashAluno *cria_tabela_hash_aluno();

int calcular_soma_ponderada(const char *nome);

void gerar_matricula(Aluno *aluno);

int hash(int matricula);

void insere_tabela_aluno(TabelaHashAluno *tabela, Aluno *aluno);

Aluno *encontra_aluno(TabelaHashAluno *tabela);

void percorrer_tabela(TabelaHashAluno *tabela);


#endif //HASHING_H
