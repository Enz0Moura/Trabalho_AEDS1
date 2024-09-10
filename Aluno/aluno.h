#ifndef ALUNO_H
#define ALUNO_H
#define MAXTAM 100
#define MAXDAY 18

#include <stdlib.h>
#include <stdio.h> // para poder usar o stdin no fgets

/* Aluno armazenará o nome do aluno, seu número de matrícula, uma lista de aulas com sua presença e a referência para a lista encadeada.*/
// presenca nao pode estar dentro de aluno pq se nao ao cadastrar um novo
// nao tenho como saber se ja existem chamadas que foram realizadas

typedef struct saladeaula SalaDeAula;

typedef struct __Aluno {
    char name[MAXTAM];
    int Mat;
    char curso[MAXTAM];
    int anoEntrada;
    struct __Aluno *prox;
    int qtdeFaltas;
    int somaNotas; //todo tem que implementas.
} Aluno;


#endif //ALUNO_H
