#include "../include/main.h"

/**
  * The function locates the last occurrence of c (converted to a char)
  * in the string pointed to by s. the terminating null character is
  * considered to be part of the string; therefore if c is '\0',
  * the function locate the terminating '\0'.
  *
  * @param s: Pointer to the source string.
  * @param c: Converted to char, the first occurrence to search for.
  * @Return: Returns a pointer to the first occurrence of the character c
  * including the '\0', else returns null if the character is absent.
*/

char * _strrchr(const char *s, int c)
{
  char * last_address = NULL;
  while (*s)
  {
    if(*s == c) last_address = ((char *)s);
    s++;
  }

  //if (last_address)
    //return (last_address);

  //if (*s == c) return ((char *)s);
  last_address = (c == '\0' && c == *s)? (char *)s : last_address;

  //return (NULL);
  return (last_address);
}
