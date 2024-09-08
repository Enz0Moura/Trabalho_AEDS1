//
// Created by enzo-moura on 9/8/24.
//

#ifndef HASHING_H
#define HASHING_H
#include <string.h>
#include "../Aluno/aluno.h"
#include "../ListaAlunos/listaalunos.h"
#include "../utils/utils.h"
#define TABLE_SIZE 100


typedef struct __Aluno Aluno;
typedef struct listaalunos ListaAlunos;


typedef struct __tabelaHashAluno {
    ListaAlunos *tabela[TABLE_SIZE];
    int indices_validos[TABLE_SIZE];
    int contador_indices;
} TabelaHashAluno;

TabelaHashAluno *cria_tabela_hash_aluno() {
    TabelaHashAluno *tabela = (TabelaHashAluno *) malloc(sizeof(TabelaHashAluno));
    return tabela;
}

int calcular_soma_ponderada(const char *nome) {
    int soma = 0;
    for (int i = 0; i < strlen(nome); i++) {
        soma += nome[i] * (i + 1);
    }
    return soma;
}

void gerar_matricula(Aluno *aluno) {
    int ano = aluno->anoEntrada % 100;

    int soma_ponderada = (calcular_soma_ponderada(aluno->name) + calcular_soma_ponderada(aluno->curso)) % 100000;

    aluno->Mat = ano * 1000000 + soma_ponderada;
}

int hash(int matricula) {
    return matricula % TABLE_SIZE;
};

void insere_tabela_aluno(TabelaHashAluno *tabela, Aluno *aluno) {
    int chave = hash(aluno->Mat);
    if (tabela->tabela[chave] == NULL) {
        tabela->tabela[chave] = listaAlunos_cria();
    }

    Aluno *aux = tabela->tabela[chave]->cabeca;
    if (aux == NULL) {
        tabela->tabela[chave]->cabeca = aluno;
        tabela->tabela[chave]->fim = aluno;
        tabela->indices_validos[tabela->contador_indices++] = chave;
        return;
    }
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = aluno;
    tabela->tabela[chave]->fim = aluno;
}

Aluno *encontra_aluno(TabelaHashAluno *tabela) {
    Aluno *novo = (Aluno *) malloc(sizeof(Aluno));
    printf("Digite o nome do aluno: ");
    fgets(novo->name, MAXTAM, stdin);
    remove_newline(novo->name);

    printf("\nDigite o Curso do aluno: ");
    fgets(novo->curso, MAXTAM, stdin);
    remove_newline(novo->curso);

    printf("\nDigite o ano de entrada do aluno: ");
    scanf("%d", &(novo->anoEntrada));
    flush_in();

    gerar_matricula(novo);
    int index = hash(novo->Mat);
    Aluno *aux = tabela->tabela[index]->cabeca;
    while (aux != NULL) {
        if (aux->Mat == novo->Mat) {
            free(novo);
            return aux;
        }
        aux = aux->prox;
    }
    free(novo);
    return NULL;
}

void percorrer_tabela(TabelaHashAluno *tabela) {
    for (int i = 0; i < tabela->contador_indices; i++) {
        int indice = tabela->indices_validos[i];
        Aluno *atual = tabela->tabela[indice]->cabeca;
        while (atual != NULL) {
            printf("Matrícula: %09d, Nome: %s, Curso: %s, Ano: %d\n",
                   atual->Mat,
                   atual->name,
                   atual->curso,
                   atual->anoEntrada);
            atual = atual->prox;
        }
    }
}



#endif //HASHING_H
