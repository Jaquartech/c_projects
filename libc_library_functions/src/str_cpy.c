#include "../include/main.h"

/**
  * The function copies the string pointed to by source to beffer
  * pointed to by dest
  *
  * @param source: Pointer to the source string
  * @param deste: Pointer to the destination string
  * @Return: Returns pointer to the destination string if successful
  * else returns nulls
*/


String _strcpy(char * dest, const char * source)
{
  char * temp = dest;

  if (!source || !dest)
  {
    return (NULL);
  }

  while (*source)
  {
    *temp++ = *source++;
  }
  *temp = '\0';

  return (dest);
}
