#include "push_swap.h"

/* This function calls ft_split() function with every command line arguments except from 
   argv[0] which is the program's name. Also it calls ft_split() function with the address
   of j because there could be more than one number in one command line argument and we have
   to keep track of the current int array index in each call of ft_split() function */
void parser(int *arr, char **str)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (str[i])
    {
        ft_split(str[i], arr, &j);
        i++;
    }
}

/* This function splits numbers or number in one command line argument in each call and
   it calls ft_strncpy() function with the beginning address of the number, size of the
   number and int *arr. It doesn't handle any error situation because passed string arguments 
   are error free due to past checks */
void ft_split(char *str, int *arr, int *nbr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (!(str[i]))
            return ;
        j = i;
        if (str[i] == '-' || str[i] == '+')
            i++;
        while (str[i] >= '0' && str[i] <= '9')
            i++;
        arr[*nbr] = ft_strncpy(&str[j], (i - j), arr);
        (*nbr)++;
    }
}

/* This function takes the beginning address of the number and size of the number
   and copy all number characters including signs free from any whitespaces to 
   str2 then it calls ft_atoi() function to convert them to integers and returns 
   the converted result */
int ft_strncpy(char *str1, int size, int *arr)
{
    int i;
    char *str2;
    int result;

    str2 = (char *)malloc(sizeof(char) * (size + 1)); 
    if (!(str2))
    {
        free(arr);
        return (1);
    }
    i = 0;
    while (i < size)
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    result = ft_atoi(str2, arr);
    free(str2);
    return (result);
}

/* It is an implementation of atoi() function which is different than the
   original one. It converts string numbers to integers but before returning
   the result it checks if the converted integer is in the range of max and min
   integer with max_check() function. It uses long int rather than integer to 
   store exceeded values to prevent overflow.  */
int ft_atoi(char *str, int *arr)
{
    long int res;
    int i;
    int sign;

    res = 0;
    i = 0;
    sign = 1;
    while (str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57)
    {
        res = (str[i] - 48) + (res * 10);
        i++;
    }
    max_check(res * sign, arr);
    return (sign * res);
}