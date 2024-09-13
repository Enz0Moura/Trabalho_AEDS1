#include "presenca.h"

Dia * criaDia(){
    Dia * aux = (Dia*)malloc(sizeof(Dia));
    aux->cabeca = NULL;
    return aux;
}

Presenca * criaPresenca(Aluno * aluno, char c){
    Presenca * aux = (Presenca*)malloc(sizeof(Presenca));
    aux->aluno = aluno;
    aux->foi = c == 'P'? 1:0;
    if(aux->foi == 0) aux->aluno->qtdeFaltas++;
    return aux;
}
