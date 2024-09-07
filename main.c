#include <stdio.h>
#include "SalaDeAula/saladeaula.h"


int main(){
    SalaDeAula * sala = saladeaula_cria();
    if (sala != NULL){
      printf("Sala De Aula criada!\n");
        for (int i = 0; i < 3; i++){
        cadastraAluno(sala);
        }
      return 0;
      }
    printf("Sala De Aula não foi criada :(\n");
    return -1;
}