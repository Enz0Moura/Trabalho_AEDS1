#ifndef PRESENCA_H
#define PRESENCA_H
#define MAX_AULAS 18
#include <stdbool.h>
#include "../Aluno/aluno.h"

/* Aula armazenará um dia de aula e a presença de um aluno como true ou false.*/
typedef struct __Aluno Aluno;

typedef struct __presenca{
    Aluno * aluno;
    bool foi;
    struct __presenca * prox; // ponteiro para a presenca do prox aluno
} Presenca;

typedef struct __dia{
    int dia;
    Presenca * cabeca;
} Dia;

typedef Dia* Aulas[MAX_AULAS]; // vetor de dias

#endif //PRESENCA_H
 