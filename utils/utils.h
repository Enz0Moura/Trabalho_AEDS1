//
// Created by enzo-moura on 9/7/24.
//

#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

void flush_in() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif //UTILS_H
