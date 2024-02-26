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
  //strchr(src, 'o');
  printf("%s\n", strchr(src, 'w'));
  if (*strchr(src, '\0') == '\0')
  {
    printf("\\0\n");
  }

  return (0);
}
