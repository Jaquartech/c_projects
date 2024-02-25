#include "../include/main.h"

/**
  * This file is a driver function which marks the entry point of
  * execution
  *
  * @param void: accepts nothing
  * @Return: Return 0 if operation is successful, otherwise a non zero
  * integer constant is returned.
*/

int main(void)
{
  char dest[100];
  const char * src = "Hello world program";
  _strcpy(dest, src);
  printf("%s\n", dest);

  return (0);
}
