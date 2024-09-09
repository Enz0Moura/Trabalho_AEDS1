#include <stdio.h>
#include "SalaDeAula/saladeaula.h"
#include "utils/utils.h"

int main() {
    SalaDeAula *sala = saladeaula_cria();
    if (sala != NULL) {
        printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
        printf("|Sistema de gerenciamento escolar                        |");
        printf("\n|Digite 1 para adicionar um aluno                      |");
        printf("\n|Digite 2 para adicionar uma avaliação                 |");
        printf("\n|Digite 3 para realizar a chamada                      |");
        printf("\n|Digite 4 para para imprimir o relatorio de alunos     |");
        printf("\n|Digite 5 para para imprimir o relatorio de notas      |");
        printf("\n|Digite 6 para sair                                    |");
        printf("\n+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
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
                    realizaChamada(sala);
                    break;
                case '4':
                    relatorioAlunos(sala);
                    break;
                case '5':
                    relatorioNotas(sala);
                    break;
                case '6':
                    return 0;
                default:
                    printf("\nOperacao invalida, tente novamente.\n");
                    break;
            }
            printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|Sistema de gerenciamento escolar                        |");
            printf("\n|Digite 1 para adicionar um aluno                      |");
            printf("\n|Digite 2 para adicionar uma avaliação                 |");
            printf("\n|Digite 3 para realizar a chamada                      |");
            printf("\n|Digite 4 para para imprimir o relatorio de alunos     |");
            printf("\n|Digite 5 para para imprimir o relatorio de notas      |");
            printf("\n|Digite 6 para sair                                    |");
            printf("\n+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
        }
    }
    return -1;
}

//todo: A maneira que estamos fazendo para armazenar as notas é MUITO custosa.
