#include "../include/main.h"

/**
  * The function locates the first occurrence of c (converted to a char)
  * in the string pointed to by s. the terminating null character is
  * considered to be part of the string; therefore if c is '\0',
  * the function locate the terminating '\0'.
  *
  * @param s: Pointer to the source string.
  * @param c: Converted to char, the first occurrence to search for.
  * @Return: Returns a pointer to the first occurrence of the character c
  * including the '\0', else returns null.
*/

char * strchr(const char *s, int c)
{
  if (!s)
  {
    return (NULL);
  }

  while (*s)
  {
    if(*s == c) return ((char *)s);
    s++;
  }

  if (*s == '\0' && c == '\0') return ((char *)s);
  return (NULL);
}
