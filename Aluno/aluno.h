#ifndef ALUNO_H
#define ALUNO_H
#define MAXTAM 100
#define MAXDAY 18
#include "presenca.h"
#include "avaliacao.h"
#include <stdio.h> // para poder usar o stdin no fgets

/* Aluno armazenará o nome do aluno, seu número de matrícula, uma lista de aulas com sua presença e a referência para a lista encadeada.*/
// presenca nao pode estar dentro de aluno pq se nao ao cadastrar um novo
// nao tenho como saber se ja existem chamadas que foram realizadas

typedef struct __Aluno {
    char name[MAXTAM];
    int Mat;
    char curso[MAXTAM];
    int anoEntrada;
    struct __Aluno *prox;
} Aluno;

typedef struct listaalunos{
    Aluno *cabeca;
    Aluno *fim;
}ListaAlunos;

void cadastraAluno(SalaDeAula * Turma){
    printf("+=-=-=-=-=-=-=-=-=+\n");
    printf("|CADASTRE UM ALUNO|");
    printf("+=-=-=-=-=-=-=-=-=+\n");    

    Aluno * novo = (Aluno*)malloc(sizeof(Aluno));
    novo->prox = NULL;

    printf("Digite o nome do aluno: ");
    fgets(novo->name, MAXTAM, stdin);

    printf("\nDigite o Curso do aluno: ");
    fgets(novo->curso, MAXTAM, stdin);

    printf("\nDigite a matricula: ");
    scanf("%d", novo->Mat);

    printf("\nDigite o ano de entrada do aluno: ");
    scanf("%d", novo->anoEntrada);

    // colocando o aluno na lista de alunos da turma
    Aluno * auxiliar = Turma->alunos->fim;
    auxiliar->prox = novo;
    Turma->alunos->fim = novo;
    

    if(Turma->aulas != NULL){
        char aux;
        int i = 0;
        while(i<MAX_AULAS && turma->aulas[i] != NULL){
            printf("\nPresenca do aluno no dia %d (P/F): ", turma->aulas[i]->dia);
            scanf("%c", &aux);
            while(aux != 'P' && aux != 'F'){
                printf("\nA presenca deve ser P ou F, digite novamente!");
                scanf("%c", &aux);
            }
            bool foi = aux == 'P'? true:false; // se foi retorna true se nao retorna false
            Presenca * hj = turma->aulas[i]->cabeca;
            while(hj->prox != NULL){
                hj = hj->prox;
            }
            Presenca * nova = (Presenca*)malloc(sizeof(Presenca));
            nova->aluno = novo;
            nova->foi = foi;
            nova->prox = NULL;

            hj->prox = nova;
            i++;
        }
    }

    if(Turma->avaliacoes != NULL){
        Avalicao * aux = Turma->avaliacoes->cabeca;
        float nota;
        while(aux != NULL){
            printf("Digite a nota do aluno na avalicao %s", aux->nome);
            scanf("%d", &nota);
            int indice = 0;
            while(aux->notas[indice] != NULL){
                indice++;
            }
            aux->notas[indice]->nota = nota;
            aux->notas[indice]->aluno = novo;
            
            aux = aux->prox;
        }
    }
}

void cadastraAvaliacao(SalaDeAula * Turma){
    Avaliacao * aux = Turma->ListaAvaliacoes->cabeca;
    Avaliacao * nova = (Avaliacao*)malloc(sizeof(Avaliacao));

    nova->prox = NULL;

    printf("Digite o nome da avaliacao: ");
    fgets(nova->nome, MAXLEN, stdin);

    printf("Digite o valor total da avaliacao: ");
    scanf("%d", nova->valortotal);

    // colocando a nota de cada aluno na avaliacao
    Aluno * alAux = Turma->alunos->cabeca;
    float nota;
    int indice = 0;
    while(alAux != NULL){
        printf("Digite a nota do aluno %s: ", alAux->nome);
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

#endif //ALUNO_H
