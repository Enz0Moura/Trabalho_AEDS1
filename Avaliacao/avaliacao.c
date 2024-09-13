#include "avaliacao.h"


ListaAvaliacoes *listaAvaliacoes_cria() {
    ListaAvaliacoes *l = (ListaAvaliacoes *) malloc(sizeof(ListaAvaliacoes));
    l->cabeca = NULL;
    return l;
};
