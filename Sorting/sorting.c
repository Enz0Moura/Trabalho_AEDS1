#include "sorting.h"

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

int calcularTamanhoVetorNotaAluno(NotaAluno **vet) {
    int count = 0;
    while (vet[count] != NULL && count < MAXLEN) {
        count++;
    }
    return count;
}

void mergeNotaAluno(NotaAluno **vet, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    NotaAluno **L = (NotaAluno **) malloc(n1 * sizeof(NotaAluno *));
    NotaAluno **R = (NotaAluno **) malloc(n2 * sizeof(NotaAluno *));

    for (int i = 0; i < n1; i++)
        L[i] = vet[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vet[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i]->nota >= R[j]->nota) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSortNotaAluno(NotaAluno **vet, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortNotaAluno(vet, left, mid);
        mergeSortNotaAluno(vet, mid + 1, right);

        mergeNotaAluno(vet, left, mid, right);
    }
}


void mergeAluno(Aluno **vet, int left, int mid, int right, int (*compara)(Aluno *, Aluno *)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Aluno **L = (Aluno **) malloc(n1 * sizeof(Aluno *));
    Aluno **R = (Aluno **) malloc(n2 * sizeof(Aluno *));

    for (int i = 0; i < n1; i++)
        L[i] = vet[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vet[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compara(L[i], R[j]) <= 0) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSortAluno(Aluno **vet, int left, int right, int (*compara)(Aluno *, Aluno *)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortAluno(vet, left, mid, compara);
        mergeSortAluno(vet, mid + 1, right, compara);

        mergeAluno(vet, left, mid, right, compara);
    }
}

void selectionSortAluno(Aluno **vet, int tamanho, int (*compara)(Aluno *, Aluno *)) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (compara(vet[j], vet[minIndex]) < 0) {
                minIndex = j;
            }
        }
        // Troca os elementos
        Aluno *temp = vet[i];
        vet[i] = vet[minIndex];
        vet[minIndex] = temp;
    }
}

void ordenarAluno(Aluno **vet, int tamanho, int (*compara)(Aluno *, Aluno *), const char m) {
    if (m == 'm') {
        mergeSortAluno(vet, 0, tamanho - 1, compara);
    } else if (m == 's') {
        selectionSortAluno(vet, tamanho, compara);
    }
}

void ordenarTabelaHash(TabelaHashAluno *tabela, int (*compara)(Aluno *, Aluno *)) {
    Aluno *listas[MAXTAM] = {NULL};

    for (int i = 0; i < tabela->contador_indices; i++) {
        int indice = tabela->indices_validos[i];
        listas[i] = tabela->tabela[indice]->cabeca;
    }

    mergeSortAluno(listas, 0, tabela->contador_indices - 1, compara);

    for (int i = 0; i < tabela->contador_indices; i++) {
        tabela->indices_validos[i] = i;
        tabela->tabela[i]->cabeca = listas[i];
    }
}

int listaParaArray(Aluno *head, Aluno **vet) {
    int count = 0;
    while (head != NULL) {
        vet[count++] = head;
        head = head->prox;
    }
    return count;
}

Aluno *arrayParaLista(Aluno **vet, int tamanho) {
    if (tamanho == 0) return NULL;
    for (int i = 0; i < tamanho - 1; i++) {
        vet[i]->prox = vet[i + 1];
    }
    vet[tamanho - 1]->prox = NULL;
    return vet[0];
}

int comparaPorNome(Aluno *a, Aluno *b) {
    return strcmp(a->name, b->name);
}

int comparaPorMatricula(Aluno *a, Aluno *b) {
    return a->Mat - b->Mat;
}

int comparaPorCurso(Aluno *a, Aluno *b) {
    // Comparação alfabética de cursos
    return strcmp(a->curso, b->curso);
}

int comparaPorAnoEntrada(Aluno *a, Aluno *b) {
    return a->anoEntrada - b->anoEntrada;
}

int comparaPorQtdeFaltas(Aluno *a, Aluno *b) {
    return a->qtdeFaltas - b->qtdeFaltas;
}

int comparaPorsomaNotas(Aluno *a, Aluno *b) {
    return a->somaNotas - b->somaNotas;
}


int calcularTamanhoVetorAluno(Aluno **vet) {
    int count = 0;
    while (vet[count] != NULL) {
        count++;
    }
    return count;
}

void imprimirListasOrdenadas(TabelaHashAluno *tabela, int (*compara)(Aluno *, Aluno *), const char algoritmo) {
    // Array para armazenar as listas encadeadas
    Aluno *listasOrdenadas[MAXTAM] = {NULL};
    int fez = 0;
    printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    printf("|%*s%s%*s|\n", 26, "", "RELATORIO DE ALUNOS", 26, "");
    printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    printHeader("MATRICULA", "NOME", "SOMA NOTAS", "FALTAS");
    printf("+-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-+-=-=-=-=-=-=-=-=-+\n");
    // Preencher o array com as listas encadeadas da tabela hash
    for (int i = 0; i < tabela->contador_indices; i++) {
        int indice = tabela->indices_validos[i];
        listasOrdenadas[i] = tabela->tabela[indice]->cabeca;

        // Ordenar cada lista encadeada internamente
        Aluno *vet[MAXTAM] = {NULL};
        int tamanho = listaParaArray(listasOrdenadas[i], vet);

        ordenarAluno(vet, tamanho, compara, algoritmo); // Escolhe o algoritmo de ordenação
        listasOrdenadas[i] = arrayParaLista(vet, tamanho); // Atualiza o array com a lista ordenada
        fez++;
    }

    // Ordenar o array de listas com base no primeiro aluno de cada lista
    ordenarAluno(listasOrdenadas, tabela->contador_indices, compara, algoritmo);

    // Imprimir as listas ordenadas
    for (int i = 0; i < tabela->contador_indices; i++) {
        Aluno *aux = listasOrdenadas[i];
        while (aux != NULL) {
            printTabela(aux->Mat, aux->name, aux->somaNotas, aux->qtdeFaltas);
            aux = aux->prox;
        }
        printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    }
    if (!fez) {
        printf("|                    NAO EXISTEM ALUNOS CADASTRADOS!                    |\n");
        printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    }
}
