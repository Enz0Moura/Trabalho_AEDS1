#include "listaalunos.h"

ListaAlunos *listaAlunos_cria() {
    ListaAlunos *l = (ListaAlunos *) malloc(sizeof(ListaAlunos));
    l->cabeca = NULL;
    l->fim = NULL;
    return l;
};
