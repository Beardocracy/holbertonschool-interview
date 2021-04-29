#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>

int advanced_binary(int *array, size_t size, int value);
void array_printer(int *array, size_t start, size_t end);
int ab_recurse(int *array, int index, int stop, int value);

#endif
