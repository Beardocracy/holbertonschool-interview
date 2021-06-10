#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void merge_two(int *array, int *temp, size_t start, size_t end, size_t middle);
void td_merge(int *temp, int *array, size_t start, size_t end);

#endif
