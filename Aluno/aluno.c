#define MAXTAM 100

typedef struct Aluno {
    int Mat;
    char name[MAXTAM];
    struct Aluno *prox;
    struct Aluno *prev;
} Aluno;

typedef struct listaalunos{
    Aluno *cabeca;
}ListaAlunos;
