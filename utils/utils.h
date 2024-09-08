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

#endif //UTILS_H
