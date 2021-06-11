#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void mergeSort(int *arr, int size, int *tmp);
void merge(int *arr, int size, int m, int *tmp);

#endif /* _SORT_H */
