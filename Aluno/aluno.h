#ifndef ALUNO_H
#define ALUNO_H
#define MAXTAM 100
#define MAXDAY 18
#include "../Presenca/presenca.h"
#include "../Avaliacao/avaliacao.h"
#include "../SalaDeAula/saladeaula.h"
#include <stdlib.h>
#include <stdio.h> // para poder usar o stdin no fgets

/* Aluno armazenará o nome do aluno, seu número de matrícula, uma lista de aulas com sua presença e a referência para a lista encadeada.*/
// presenca nao pode estar dentro de aluno pq se nao ao cadastrar um novo
// nao tenho como saber se ja existem chamadas que foram realizadas

//todo adicionar forma de armazenar faltas

typedef struct saladeaula SalaDeAula;

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

void cadastraAluno(SalaDeAula * turma){
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
    Aluno * auxiliar = turma->alunos->fim;
    auxiliar->prox = novo;
    turma->alunos->fim = novo;
    

    if(turma->aulas != NULL){
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

    if(turma->avaliacoes != NULL){
        Avaliacao * aux = turma->avaliacoes->cabeca;
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

#endif //ALUNO_H
