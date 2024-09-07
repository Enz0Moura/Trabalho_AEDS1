#ifndef AVALIACAO_H
#define AVALIACAO_H
#define MAXLEN 100
#include "../Aluno/aluno.h"
#include "../SalaDeAula/saladeaula.h"
/* Avaliação armazenará uma lista de alunos com suas respectivas notas.
* Armazenará o valor total para o cálculo da média do aluno.
* */

typedef struct __Aluno Aluno;
typedef struct saladeaula SalaDeAula;

typedef struct _notaaluno{
    float nota;
    Aluno *aluno;
} NotaAluno;

// todo cria avaliacao inicializa notas com NULL
typedef struct __avaliacao{
    char nome[MAXLEN];
    float valortotal;
    NotaAluno* notas[MAXLEN];
    struct __avaliacao *prox;
} Avaliacao;

typedef struct __listaavaliacoes{
    Avaliacao *cabeca;
} ListaAvaliacoes;

void cadastraAvaliacao(SalaDeAula * Turma){
    Avaliacao * aux = Turma->avaliacoes->cabeca;
    Avaliacao * nova = (Avaliacao*)malloc(sizeof(Avaliacao));

    nova->prox = NULL;

    printf("Digite o nome da avaliacao: ");
    fgets(nova->nome, MAXLEN, stdin);

    printf("Digite o valor total da avaliacao: ");
    scanf("%f", nova->valortotal);

    // colocando a nota de cada aluno na avaliacao
    Aluno * alAux = Turma->alunos->cabeca;
    float nota;
    int indice = 0;
    while(alAux != NULL){
        printf("Digite a nota do aluno %s: ", alAux->name);
        scanf("%f", &nota);
        nova->notas[indice]->aluno = alAux;
        nova->notas[indice]->nota = nota;
        indice++;
    }

    while(aux != NULL && aux->prox != NULL){
        aux = aux->prox;
    }
    if(aux == NULL){ // se for a primeira avaliacao
        aux = nova;
        return;
    }
    aux->prox = nova;   // se ja tiverem avaliacoes cadastradas
    
}

#endif //AVALIACAO_H
