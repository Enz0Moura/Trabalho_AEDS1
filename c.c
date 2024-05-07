#include <stdio.h>
#define MAXTAM 100

typedef struct Aluno {
    int Mat;
    char name[MAXTAM];
    struct Aluno *prox;
    struct Aluno *prev;
} Aluno;

/* Usar hashing duplo*/

void main(){
}