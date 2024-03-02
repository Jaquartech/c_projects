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

  char * result = _strrchr(src, 'r');
  if (result)
  {
    printf("%zu\n", result - src);
  }

/*if (*strchr(src, '\0') == '\0')
  {
    printf("\\0 \n");
  }*/

  return (0);
}
