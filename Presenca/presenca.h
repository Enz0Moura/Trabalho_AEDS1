#ifndef PRESENCA_H
#define PRESENCA_H
#define MAX_AULAS 18
#include <stdbool.h>
#include "../Aluno/aluno.h"
#include "../SalaDeAula/saladeaula.h"

/* Aula armazenará um dia de aula e a presença de um aluno como true ou false.*/
typedef struct __Aluno Aluno;

typedef struct saladeaula SalaDeAula;

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


//todo dps da implementacao da qtdeFaltas fazer a verificacao 
//se qtdeFaltas chegar a 10 printar aviso de reprovacao por falta
void realizaChamada(SalaDeAula * turma){
    int data;
    
    printf("\nDigite a data da aula: ");
    scanf("%d", &data);
    
    int i = 0;
    Dia * auxiliar;
    while (turma->aulas[i+1] != NULL)
    {
        i++;
    }

    auxiliar = turma->aulas[i];
    Presenca * auxPre = turma->aulas[i]->cabeca;
    Aluno * alAux = turma->alunos->cabeca;
    char c;
    // fazendo para o primeiro cara 
    printf("Marque a presenca do aluno %s (P/F)", alAux->nome);
    scanf("%c", &c);
    while(c != 'P' && c != 'F'){
        printf("\nA presenca deve ser P ou F, digite novamente!");
        scanf("%c", &c);
    }
    bool esteve; = c == 'P'? true:false; // se foi retorna true se nao retorna false
    auxPre->aluno = alAux;
    auxPre->foi = esteve;   
    alAux = alAux->prox;
    // continuo na cabeca
    while(alAux != NULL){
        Presenca * auxPre2;
        printf("Marque a presenca do aluno %s (P/F)", alAux->nome);
        scanf("%c", &c);
        while(c != 'P' && c != 'F'){
                printf("\nA presenca deve ser P ou F, digite novamente!");
                scanf("%c", &c);
            }
        esteve = c == 'P'? true:false; // se foi retorna true se nao retorna false
        auxPre2->aluno = alAux;
        auxPre2->foi = esteve;
        auxPre->prox = auxPre2;
        auxPre = auxPre2; 
        alAux = alAux->prox;  
    }
}   

#endif //PRESENCA_H
 