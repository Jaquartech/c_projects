// This file conatains function prototype and Macros for the array project

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void _swap(void *a, void *b, size_t size);
int secondGreatestValue(int *ptr, unsigned int len);
int greatestValue(int array[], unsigned int len);
void reverse(int array[], unsigned int len);
void display(int *ptr, unsigned int len);
void reverse_optimise(void * array, unsigned int len, size_t size);
void display_optimized(void *ptr, unsigned int len, size_t size, void (*type_print_func)(void *));

#endif // !ARRAY_H