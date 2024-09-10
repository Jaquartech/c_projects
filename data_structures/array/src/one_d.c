#include "array.h"

/**
 * @brief The function takes two data by  by reference and swap thier values
 * 
 * @param a: pointer to the variable a
 * @param b: pointer to the variable b
 * @return: returns nothing
 */
void _swap(void *a, void *b, size_t size)
{
    void *temp = (void *) malloc(size);
    
    if (temp != NULL)
    {
        memcpy(temp, a, size);
        memcpy(a, b, size);
        memcpy(b, temp, size);
        free(temp);
    }
}

/**
 * @brief The function takes a pointer to an Array conatainer, iterates over
 * it, and returns the second greatest integer.
 * 
 * @param ptr: Pointer to the Array container
 * @param len: Length of the Array container
 * @return: Returns the greatest value in the Array conatiner
 * else returns -1 if container is empty or length is less than 1
 */
int secondGreatestValue(int *ptr, unsigned int len)
{
    int max = INT_MIN; int second_max = INT_MIN;
    if (!ptr)
    {
        printf("No array conatainer\n");
        return second_max;
    }
    if (len < 1)
    {
        printf("length cannot be less than one\n");
        return second_max;
    }
    
    for (size_t i = 0; i < len; i++)
    {
        if (*(ptr + i) > max)
        {
            second_max = max;
            max = *(ptr + i);
        }
        else if (*(ptr + i) > second_max && *(ptr + i) != max)
        {
            second_max = *(ptr + i);
        }
    }
    return second_max;
}

/**
 * @brief The function takes a pointer to an array, iterates over
 * it, and returns the greatest integer.
 * 
 * @param array: Pointer to the Array container
 * @param len: Length of the Array container
 * @return: Returns the greatest value in the Array conatiner
 * else returns -1 if container is empty or length is less than 1
 */
int greatestValue(int array[], unsigned int len)
{
      if (!array)
    {
        printf("No array conatainer\n");
        return -1;
    }
    if (len < 1)
    {
        printf("length cannot be less than one\n");
        return -1;
    }

    unsigned index = 0;

    int max = array[index];

    for (index++; index < len; index++)
    {
        if (array[index] > max)
        {
            max = array[index];
        }   
    }
    
    return max;
}

/**
 * @brief The function takes a pointer to an integer type array, iterates over
 * it, and reverses the content of the array.
 * 
 * @param array: Pointer to the Array container
 * @param len: Length of the Array container
 * @return: Returns nothing
 */
void reverse(int array[], unsigned int len)
{
     if (!array)
    {
        printf("No array conatainer\n");
        return;
    }
    if (len < 1)
    {
        printf("length cannot be less than one\n");
        return;
    }
     int * start = array;
     int * end = array + len - 1;

     while (start < end)
     {
        _swap(start, end, sizeof(int));
        start++;
        end--;
     }
     
}

/**
 * @brief The function  takes a pointer to an array of any primitive type,
 * iterates over it and reverses it.
 * 
 * @param array Pointer to the Array container
 * @param len Length of the Array container
 * @param size size of the data type
 * @return: Returns nothing
 */
void reverse_optimized(void * array, unsigned int len, size_t size)
{
     if (!array)
    {
        printf("No array conatainer\n");
        return;
    }
    if (len < 1)
    {
        printf("length cannot be less than one\n");
        return;
    }
     char * start = (char *) array;
     
     char * end = start + (len - 1) * size;
     
     while (start < end)
     {
        _swap(start, end, size);

        start += size;
        end -= size;
        
     }
     
}

/**
 * @brief The function  takes a pointer to an integer type
 * array iterates over it and reverses it.
 * 
 * @param array Pointer to the Array container
 * @param len Length of the Array container
 * @return: Returns nothing
 */
void display(int *ptr, unsigned int len)
{
     if (!ptr)
    {
        printf("No array conatainer\n");
        return;
    }
    if (len < 1)
    {
        printf("length cannot be less than one\n");
        return;
    }
    for (unsigned int i = 0; i < len; i++)
  {
    printf("%d  ", ptr[i]);
  }
  printf("\n");
}

/**
 * @brief The function  takes a pointer to an
 * array of any primitive type, iterates over it and displays the content.
 * 
 * @param ptr Pointer to the Array container
 * @param len Length of the Array container
 * @param size size of the data type
 * @param type_print_func pointer to a function which 
 * accepts a pointer to void type as argument and returns nothing 
 * @return: Returns nothing
 */
void display_optimized(void *ptr, unsigned int len, size_t size, void (*type_print_func)(void *))
{
     if (!ptr)
    {
        printf("No array conatainer\n");
        return;
    }
    if (len < 1)
    {
        printf("length cannot be less than one\n");
        return;
    }

    for(unsigned int i = 0; i < len; i++)
    {
        type_print_func((char *)ptr + i * size);
    }
  printf("\n");
}

/**
 * @brief The function positive_int takes data array of integer numbers
 * and returns the length of new data array containing even integers.
 * the array argument is modified in place.
 * 
 * @param source Source containing data
 * @param dest destinatinon to to conatain array data of even integers
 * @param len Length of the source array data
 * @return Returns the lenght of dest containing array data of ven numbers
 */
int even_int(int *source, int **dest, unsigned int len)
{
    if (!source)
    {
        printf("Array is empty\n");
        return -1;
    }
    if (!len)
    {
        printf("Length is zero\n");;
        return -1;
    }
    
    unsigned int index = 0, counter = 0;
    for (; index < len; index++)
    {
        if (source[index] % 2 == 0)
        {
            counter++;
        }   
    }
    *dest = malloc(sizeof(int) * counter);
    if (!(*dest))
    {
        printf("Failed to allocate memroy\n");
        return -1;
    }
    unsigned int counts = 0;
    unsigned int index_new = 0;
    for (; counts < len; counts++)
    {
        if ( source[counts] % 2 == 0)
        {
            (*dest)[index_new++] = source[counts];
        }   
    }
    return counter;  
}

/**
 * @brief The function tackes an array data, and moves the zero
 * elements to the end, while maintaining the relative positions
 * of the non zero elements
 * 
 * @param array Pointer to the pointer to a one dimensional array
 * @param len Length of the array data
 * @return Returns nothing
 */
void move_zeros(int **array, unsigned int len)
{
    unsigned int i = 0;
    int j = 0;
    if (!(*array))
    {
        printf("No array conatainer\n");
        return;
    }
    if (len < 1)
    {   
        printf("length cannot be less than one\n");
        return;
    }
    for (; i < len; i++)
    {
        if ((*array)[i] != 0 && (*array)[j] == 0)
            _swap(&(*array)[i], &(*array)[j], sizeof(int));
        if ((*array)[j] != 0)
            j++;
    }
}

/**
 * @brief The function tackes an array data and dynamically resizes
 * it in place, filling the remaing spaces with zeroes
 * 
 * @param array Pointer to the pointer to a one dimensional array
 * @param len Length of the array data
 * @return Returns lenghh of the newly resized array
 */
int resize_array(int ** array, unsigned int len)
{
    unsigned int i = 0;
    
    if (!(*array))
    {
        printf("No array conatainer\n");
        return -1;
    }
    if (len < 1)
    {   
        printf("length cannot be les than one\n");
        return -1;
    }
    unsigned int new_len = 2* len;
    int *ptr =(int *)calloc(new_len, sizeof(int));
    printf("ptr inside =%p\n", ptr);
    if (!ptr)
    {
        return -1;
    }
    for (; i < len; i++)
    {
        ptr[i] = (*array)[i];
    }
    *array = ptr;
    return new_len;
}

/**
 * @brief The function tackes an array data, having n-1 sequence number
 * of elements, and returns the missing number
 * 
 * @param array Pointer to the pointer to a one dimensional array
 * @param len Length of the array data
 * @return Returns the missing number
 */
int missing_number(int ** array, unsigned int len)
{
    unsigned int i = 0;
    int sum = 0;
    if (!(*array))
    {
        printf("No array conatainer\n");
        return -1;
    }
    if (len < 1)
    {   
        printf("length cannot be less than one\n");
        return -1;
    }
    int n = 1 + len;
    sum = n * (n + 1) / 2;
    for (; i < len; i++)
    {
        sum -= (*array)[i];
    }
    
    return sum;
}



bool isPalindrome(const char * array, unsigned int len)
{
    if (!array)
    {
        printf("No array conatainer\n");
        return -1;
    }
    if (len < 1)
    {   
        printf("length cannot be less than one\n");
        return -1;
    }
    unsigned start = 0, end = len - 1;
    
    for (; start < end; start++)
    {
        if (array[start] != array[end])
        {
            printf("from f\n");
            return false;
        }
        end--;
    }
    
    return true;
}

/**
 * @brief: takes a byte level pointer to a float and prints the value
 * @param: Byte pointer to the float type
 * @return: Returns nothing
 */
void printFloat(void * p)
{
    printf("%0.2f ", *(float *)p);
}

/**
 * @brief: takes a pointer to a character and prints the value
 * @param: Byte pointer to the character type
 * @return: Returns nothing
 */
void printChar(void * p)
{
    printf("%c ", *(char *)p);
}

/**
 * @brief: takes a byte level pointer to an int and prints the value
 * @param: Byte pointer to the int type
 * @return: Returns nothing
 */
void printInt(void * p)
{
    printf("%d ", *(int *)p);
}