#include "push_swap.h"

int main(int argc, char **argv)
{
    int total_number;
    int i;
    int *arr;
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    total_number = 0;
    i = 1;
    if (argc == 1)
        return (0);
    while (argv[i])
    {
        non_numeric_check(argv[i]);
        total_number = total_number + number_counter(argv[i]);
        i++;
    }
    arr = (int *)malloc(sizeof(int) * (total_number));
    parser(arr, argv);
    duplicate_check(arr, total_number);
    sorted_check(arr, total_number);
    create_and_sort_stack(&a, &b, arr, total_number);
}