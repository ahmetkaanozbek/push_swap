#include "push_swap.h"

/* It frees and exit from the program when it fails to create a space in heap
   with using malloc */
void free_and_exit(int *arr, int *cpy_arr)
{
    free(arr);
    free(cpy_arr);
    exit(EXIT_FAILURE);
}

/* This function checks if the numbers in the given argument is already sorted */
void sorted_check(int *arr, int total)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < (total - 1))
    {
        if (arr[i] > arr[i + 1])
            count++;
        i++;
    }
    if (count == 0)
        exit(EXIT_SUCCESS);
}

/* To sort the given numbers with the given instructions and with applying the
   the limited number of instructions, this program uses radix algorithm. However,
   the project's rules says there can only be 2 stacks. Due to that to use radix algo
   numbers should be in binary order so we can store 1s and 0s in two stacks. But also,
   the given numbers could be negative too and to not deal with the negative binary 
   numbers we have to give positive numbers, starting from zero, to every given numbers. 
   However, this number should represent their values which means:  
                        
                        The given numbers: -19 32 21 0 42
     Their values to sort them with radix:  0  3  2  1 4      
    
    After giving the values or positions like this function's name the program can sort 
    them with using radix algortihm.  
*/
int *find_positions(int *arr, int *cpy_arr, int total)
{
    int i;
    int j;
    int *pos_arr;

    i = 0;
    j = 0;
    pos_arr = malloc(sizeof(int) * total);
    if (!(pos_arr))
        free_and_exit(arr, cpy_arr);
    while (i < total)
    {
        while (j < total)
        {
            if (cpy_arr[i] == arr[j])
            {
                pos_arr[j] = i;
                break;
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (pos_arr);
}

/* This function sorts the copy array with bubble sort algorithm to compare it
   with the original array */
void sort_cpy_arr(int *cpy_arr, int total)
{
    int i;
    int temp;

    i = 0;
    while (i < (total - 1))
    {
        if (cpy_arr[i] > cpy_arr[i + 1])
        {
                temp = cpy_arr[i];
                cpy_arr[i] = cpy_arr[i + 1];
                cpy_arr[i + 1] = temp;
                i = 0;
        }
        else
            i++;
    }
}

/* It creates a copy of the integers array then it calls a function to sort the
   copy array and it also calls function to find the positions of the numbers
   to sort them with radix algorithm */
int *cpy_and_sort_array(int *arr, int total)
{
    int *cpy_arr;
    int *pos_arr;
    int i;

    i = 0;
    cpy_arr = malloc(sizeof(int) * total);
    if (!(cpy_arr))
    {
        free(arr);
        exit(EXIT_FAILURE);
    }
    while (i < total)
    {
        cpy_arr[i] = arr[i];
        i++;
    }
    sort_cpy_arr(cpy_arr, total);
    pos_arr = find_positions(arr, cpy_arr, total);
    free(cpy_arr);
    return (pos_arr);
}