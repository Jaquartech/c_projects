#include "../include/main.h"

/**
  * The function take a pointer to a string and returns the length
  * of the string excluding the null charater.
  *
  * @param ptr: Pointer to the first byte of the string literal
  * @Return: Returns length of the string literal if successful else
  * returns -1 if the pointer is null
*/

size_t _strlen(String ptr)
{
  size_t counter = 0;
  if(!ptr)
  {
    printf("ERROR: ptr cannot be null\n");
    return (-1);
  }

  while (*ptr)
  {
    counter++;
    ptr++;
  }

  return (counter);
}
