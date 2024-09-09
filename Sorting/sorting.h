//
// Created by enzo-moura on 9/9/24.
//

#ifndef SORTING_H
#define SORTING_H
#include "../Avaliacao/avaliacao.h"

void troca(NotaAluno **vet, int i, int j) {
    NotaAluno *aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void selectionSortNotaAluno(NotaAluno **vet) {
    int maior;
    int i = 0;
    int j;
    while (vet[i] != NULL && i < MAXLEN) {
        maior = i;
        j = i + 1;
        while (vet[j] != NULL && j < MAXLEN) {
            if (vet[j]->nota > vet[maior]->nota) {
                maior = j;
            }
            j++;
        }
        troca(vet, i, maior);
        i++;
    }
}

#endif //SORTING_H
