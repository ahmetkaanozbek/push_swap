#include "push_swap.h"

/* This function calculates the total number of the numbers in one command line argument
   It is crucial due to these kind of arguments: "2 3 4 " or " 2 3 -4" which means there
   could be more than one number in one command line argument. If there is no number such
   as " " it calls exit() function to terminate the program */
int number_counter(char *str)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (str[i])
            counter++;
        while (str[i] <= '9' && str[i] >= '0')
            i++;
    }
    if (counter == 0)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    return (counter);
}

/* It checks if there is any character than '0' to '9', ' ' and '-', '+' and if there is any,
   it calls exit() function and terminate the program and also it calls sign_check() function
   to check if the arguments convenient in terms of requirements */
void non_numeric_check(char *str)
{
    int i; 

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != ' '))
        {
            if (str[i] != '+' && str[i] != '-')
            {
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
        }
        i++; 
    }
    sign_check(str);
}

/* It checks if the given argument is valid in terms of required sign usage: 1- If 
   there is a sign there should be a number immediately after it 2- There shouldn't be
   any sign characters after the last number of the argument such as "-112-12". If it fails
   the function will call exit() to terminate the program */
void sign_check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '-' || str[i] == '+')
        {
            i++;
            if (!(str[i] >= '0' && str[i] <= '9'))
            {
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
        }
        while (str[i] >= '0' && str[i] <= '9')
            i++;
        if (str[i] == '-' || str[i] == '+')
        {
             write(2, "Error\n", 6);
             exit(EXIT_FAILURE);
        }
        i++;
    }
}

/* It checks if there is any duplicate number in the int array arr. If there is any it
   frees arr array and call exit() function to terminate the program */
void duplicate_check(int *arr, int total_number)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < total_number)
    {
        while (j < i)
        {
            if (arr[j] == arr[i])
            {
                free(arr);
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        j = 0;
        i++;
    }
}

/* Numbers should be in the range of max int and min int which are 2147483647, -2147483648
   respectively. To check that variable which holds numbers should be 8 byte long int to 
   prevent overflow. If it exceeds the max and min ranges, function frees arr and 
   calls exit() function to terminate the program */
void max_check(long int nbr, int *arr)
{
    if ((nbr > 2147483647) || (nbr < -2147483648))
    {
        free(arr);
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
}