// #include "main.h"
//#include "array.h"
#include "lists.h"

/**
  * This file is a driver function which marks the entry point of
  * execution
  *
  * @param void: accepts nothing
  * @Return: Return 0 if operation is successful, otherwise a non zero
  * integer constant is returned.
*/

student *head = NULL;
unsigned int count = 0;
int main(void)
{
    addFirst(&head, "Chris", 24);
    addFirst(&head, "Ifeanyi", 30);
    addFirst(&head, "Chima", 28);
    // addLast(&head, "Ada", 27);
    //addLast(&head, "Uche", 31);
    addAt(&head, "Miracle", 32, 0);
    addAt(&head, "Charles", 36, 1);
    ///addAt(&head, "Favor", 32, 5);

    unsigned int s = size();
    printf("Size = %d\n", s);

    display_(head);

    //deleteFirst(&head);
    //deleteFirst(&head);
    deleteAt(&head, 6);
    unsigned int s_1 = size();

    printf("Size = %d\n", s_1);

    display_(head);

  return (0);
}
