#include "main.h"
#include "array.h"

/**
  * This file is a driver function which marks the entry point of
  * execution
  *
  * @param void: accepts nothing
  * @Return: Return 0 if operation is successful, otherwise a non zero
  * integer constant is returned.
*/

void printFloat(void * p)
{
    printf("%0.2f ", *(float *)p);
}

void printChar(void * p)
{
    printf("%c ", *(char *)p);
}

void printInt(void * p)
{
    printf("%d ", *(int *)p);
}

int main(void)
{
  // char char_array[] = "hello";
  // int int_array[] = {79, 2, 48, 23, 90, 50, 101, 92};
  // float float_array[] = {7.9, 20.7, 48.09, 23.76, 90.7, 5.02, 101.8, 92.0};
  
  // int len_char = sizeof(char_array) / sizeof(char_array[0]);
  // int len_int = sizeof(int_array) / sizeof(int_array[0]);
  // int len_float = sizeof(float_array) / sizeof(float_array[0]);

  // printf("\n\n");

  // display_optimized(char_array, len_char, sizeof(char), printChar);
  // reverse_optimized(char_array,len_char, sizeof(char));
  // display_optimized(char_array, len_char, sizeof(char), printChar);

  // printf("\n\n");

  // display_optimized(int_array, len_int, sizeof(int), printInt);
  // reverse_optimized(int_array, len_int, sizeof(int));
  // display_optimized(int_array, len_int, sizeof(int), printInt);

  // printf("\n\n");

  // display_optimized(float_array, len_float, sizeof(float), printFloat);
  // reverse_optimized(float_array, len_float, sizeof(float));
  // display_optimized(float_array, len_float, sizeof(float), printFloat);

  int int_array[] = {79, 2, 48, 23, 90, 50, 101, 92};
  int * ptr = NULL;
  int len_int = sizeof(int_array) / sizeof(int_array[0]);
  int len_new =  even_int(int_array, &ptr, len_int);
  display(ptr, len_new);

  return (0);
}
