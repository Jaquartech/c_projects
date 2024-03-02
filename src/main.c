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
  const char * src = "Hello world program";

  char * result = _strchr(src, 'q');
  if (result)
  {
    printf("%zu\n", result - src);
    if (*result != '\0')
    {
      printf("%s\n", result);
    }
    else
    printf("\\0\n");
  }
  else
  printf("null\n");

  return (0);
}
