//
// Created by enzo-moura on 9/9/24.
//

#ifndef SORTING_H
#define SORTING_H
#include "../Avaliacao/avaliacao.h"
#include "../utils/utils.h"
#include "../Hashing/hashing.h"


void troca(NotaAluno **vet, int i, int j);

void selectionSortNotaAluno(NotaAluno **vet);

int calcularTamanhoVetorNotaAluno(NotaAluno **vet);

void mergeNotaAluno(NotaAluno **vet, int left, int mid, int right);

void mergeAluno(Aluno **vet, int left, int mid, int right, int (*compara)(Aluno *, Aluno *));

void mergeSortAluno(Aluno **vet, int left, int right, int (*compara)(Aluno *, Aluno *));

void selectionSortAluno(Aluno **vet, int tamanho, int (*compara)(Aluno *, Aluno *));

void mergeSortNotaAluno(NotaAluno **vet, int left, int right);

void ordenarAluno(Aluno **vet, int tamanho, int (*compara)(Aluno *, Aluno *), const char m);

void ordenarTabelaHash(TabelaHashAluno *tabela, int (*compara)(Aluno *, Aluno *));

int listaParaArray(Aluno *head, Aluno **vet);

Aluno *arrayParaLista(Aluno **vet, int tamanho);

int comparaPorNome(Aluno *a, Aluno *b);

int comparaPorMatricula(Aluno *a, Aluno *b);

int comparaPorCurso(Aluno *a, Aluno *b);

int comparaPorAnoEntrada(Aluno *a, Aluno *b);

int comparaPorQtdeFaltas(Aluno *a, Aluno *b);

int comparaPorsomaNotas(Aluno *a, Aluno *b);

int calcularTamanhoVetorAluno(Aluno **vet);

void imprimirListasOrdenadas(TabelaHashAluno *tabela, int (*compara)(Aluno *, Aluno *), const char algoritmo);


#endif //SORTING_H
