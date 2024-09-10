//
// Created by enzo-moura on 9/7/24.
//

#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <string.h>

void flush_in() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}


void printTabela(int mat, char * name, float notas, int faltas){
    printf("| %-15d | %-15s | %-15.2f | %-15d |\n", mat, name, notas, faltas);
}

void printHeader(char * s1, char * s2, char * s3, char * s4){
    printf("| %-15s | %-15s | %-15s | %-15s |\n", s1, s2, s3, s4);
}
#endif //UTILS_H
