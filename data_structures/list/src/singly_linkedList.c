#include "lists.h"

/**void
 * @brief Creates node
 */
student * createNode(char * name, int age)
{   
    student *new_node = malloc(sizeof(student));
    if (!new_node)
    {
        fprintf(stderr, "Unable to allocate memory\n");
        return NULL;
    }
       
    if(!initializeNode(new_node, name, age))
    {
        fprintf(stderr, "Initializer error\n");
        free(new_node);
        return NULL;
    };
    return new_node;
}

int initializeNode(student *ptr, char * name, int age)
{
    unsigned int len = strlen(name);
    ptr->name = malloc(len + 1);
    if (!ptr->name)
    {
        fprintf(stderr, "Unable to allocate memory\n");
        return (0);
    }
    
    strcpy(ptr->name,name);
    ptr->age = age;
    ptr->next = NULL;
    return (1);
}

void addFirst(student **ptr, char * name, int age)
{
    if ((!name || strcmp(name, " ") == 0) && (age <= 0))
    {
        fprintf(stderr, "From function addFirst:: Name or age must have a value\n");
        return;
    } 
    student *new_st = createNode(name, age);
    if (isEmpty(*ptr))
    {
        *ptr = new_st;
        count++;
        return;
    }
    new_st->next = *ptr;
    *ptr = new_st;
    count++;
}

void display_(student *ptr)
{
    if (!ptr)
    {
        fprintf(stderr, "NULL pointer\n");
        return;
    }
    
    while (ptr)
    {
        printf("(%s, ", ptr->name);
        printf("%d)", ptr->age);
        printf("->");
        ptr = ptr->next;
    }
    printf("null\n");
}

bool isEmpty(student * ptr)
{
    return ptr == NULL;
}

unsigned int size(/*student *ptr*/)
{
   return count;
}

void addLast(student **ptr, char * name, int age)
{
    if ((!name || strcmp(name, " ") == 0) && (age <= 0))
    {
        fprintf(stderr, "From function addLast:: Name or age must have a value\n");
        return;
    }
    student *current = *ptr;
    student *new_st = createNode(name, age);
    if (isEmpty(*ptr))
    {
        *ptr = new_st;
        count++;
        return;
    }

     while (current->next)
        current = current->next;

    current->next = new_st;
    count++;
}

void addAt(student **ptr, char * name, int age, int position)
{
    if ((!name || strcmp(name, " ") == 0) && (age <= 0 || position < 0))
    {
        fprintf(stderr, "From function addAt:: Name, Age or Position error\n");
        return;
    }
    int at = 0;
    student *current = *ptr;
    student *temp = NULL;
    student *new_st = createNode(name, age);
    if (isEmpty(*ptr))
    {
        *ptr = new_st;
        count++;
        return;
    }
    
    if (position == 0)
    {
        addFirst(ptr, name, age);
        return;
    }

    while ((at < position - 1) && (current->next))
    {
        current = current->next;
        at++;
    }

    if (!current->next)
    {
        fprintf(stderr, "from function addAt:: Out of bound exception\n");
        return;
    }
    
    temp = current->next;
    current->next = new_st;
    new_st->next = temp;
    count++;
}

void deleteFirst(student **ptr)
{
    if (isEmpty(*ptr))
    {
        fprintf(stderr, "Empty: can't delete\n");
        return;
    }
    student *temp = *ptr;
    *ptr = ( *ptr)->next;
    count--;
    free(temp);   
}

void deleteLast(student **ptr)
{
    if (isEmpty(*ptr))
    {
        fprintf(stderr, "From function deleteLast:: Null pointer can't be delete\n");
        return;
    }

    student * current = *ptr;
    student * previous = *ptr;
    if ((*ptr)->next == NULL)
    {
        free(*ptr);
        count--;
        return;
    }

    while (current->next)
    {
        previous = current;
        current = current->next;
    }

    free(previous->next);
    previous->next = NULL;
    current = NULL;
    count--;
}


void deleteAt(student **ptr, unsigned int position)
{
    if (isEmpty(*ptr))
    {
        fprintf(stderr, "From function deleteAt:: Null pointer can't be delete\n");
        return;
    }
    if (position > count)
    {
        fprintf(stderr, "From function deleteAt:: Out of bound Exception\n");
        return;
    }
    unsigned int count_ = 0;
    if (position == 0)
    {
       deleteFirst(ptr);
        return;
    }

    student * current = *ptr;
    student * previous = *ptr;
    while (current->next && count_  < position)
    {
        previous = current;
        current = current->next;
        count_++;
    }

    if (!previous)
    {
        fprintf(stderr, "Iteration produced a NULL pointer: \n");
        return;
    }
    
    if (current)
    {
        previous->next = current->next;
        free(current);
        count--;
        return;
    }

    if ((!current && previous))
    {
        deleteLast(ptr);
        return;
    }
    else
    {
        fprintf(stderr, "Error: Out of bound\n");
        return;
    }
    
}