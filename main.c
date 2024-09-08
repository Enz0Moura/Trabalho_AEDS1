#include <stdio.h>
#include "SalaDeAula/saladeaula.h"
#include "utils/utils.h"

int main() {
    SalaDeAula *sala = saladeaula_cria();
    if (sala != NULL) {
        printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
        printf("|Sistema de gerenciamento escolar       |");
        printf("\n|Digite 1 para adicionar um aluno     |");
        printf("\n|Digite 2 para adicionar uma avaliação|");
        printf("\n|Digite 3 para sair                   |");
        printf("\n+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
        char operacao;
        while (1) {
            scanf("%c", &operacao);
            flush_in();
            switch (operacao) {
                case '1':
                    cadastraAluno(sala);
                    break;
                case '2':
                    cadastraAvaliacao(sala);
                    break;
                case '3':
                    return 0;
                default:
                    printf("\nOperacao invalida, tente novamente.\n");
            }
            printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
            printf("|Digite 1 para adicionar um aluno     |");
            printf("\n|Digite 2 para adicionar uma avaliação|");
            printf("\n|Digite 3 para sair                   |");
            printf("\n+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n");
        }
    }
    return -1;

    cadastraAluno(sala);
}
//todo: A maneira que estamos fazendo para armazenar as notas é MUITO custosa.