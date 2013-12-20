#ifndef _SORT_PUBLIC_H
#define _SORT_PUBLIC_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insert_sort(int*p, int num);
void shell_sort(int*p, int num);
void bubble_sort(int*p, int num);
void quick_sort(int*p, int num);
void merge_sort(int*p, int num);
void heap_sort(int*p, int num);
int get_max_len(const char*p);
int* prepare_rule(const char* search, int *len);

#endif
