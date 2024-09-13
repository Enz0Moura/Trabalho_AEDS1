//
// Created by enzo-moura on 9/7/24.
//

#ifndef LISTAALUNOS_H
#define LISTAALUNOS_H
#include "../Aluno/aluno.h"
#include <stdlib.h>

typedef struct __Aluno Aluno;

typedef struct listaalunos {
    Aluno *cabeca;
    Aluno *fim;
} ListaAlunos;

ListaAlunos *listaAlunos_cria();

#endif //LISTAALUNOS_H
