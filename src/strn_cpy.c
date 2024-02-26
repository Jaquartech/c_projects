#include "../include/main.h"

/**
  * The function copies n bytes of character from the string pointed by
  * source to the string pointed to by dest Pointer
  *
  * @param source: Pointer to the source string
  * @param dest: Pointer to the destination buffer
  * @param len: Number of bytes to copy
  * @Return: Returns pointer to the destination pointer
*/

char * _strncpy(char * dest, const char * source, size_t len)
{
  if (!dest || !source || !len)
  {
    return NULL;
  }

  char * dest_iter = dest;

  while (len && *source)
  {
    *dest_iter++ = *source++;
    len--;
  }

  if (len)
  {
    while (len)
    {
      *dest_iter++ = '\0';
      len--;
    }
  }

  return (dest);
}
