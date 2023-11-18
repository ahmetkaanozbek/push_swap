#include "push_swap.h"

/* Instruction page says if the total number of the given numbers are less than or
   equal to 5, number of the instructions which will be executed to sort numbers should
   be little which means: for 3 numbers there should be max 3 instructions and for 5 numbers
   there should be max 12 instructions. Therefore, using radix algo wouldn't be compatible.
   This function calls several functions to sort max 5 numbers with using different algorithm
   than radix */
void simple_sort(t_stack **a, t_stack **b, int total)
{
    if (total == 1)
        return ;
    else if (total == 2)
        sort_two(a);
    else if (total == 3)
        sort_three(a);
    else if (total == 4)
        sort_four(a, b);
    else if (total == 5)
        sort_five(a, b);
}

/* It sorts the numbers if there is only two numbers */
void sort_two(t_stack **a)
{
    if ((*a)->position > ((*a)->next)->position)
        ra(a);
}

/* This function sorts four numbers. Firstly, it sorts the first three then 
   push the biggest number to stack a and call ra() to sort them correctly */
void sort_four(t_stack **a, t_stack **b)
{
    int three_position;

    three_position = find_three(*a);
    rotate_three_for_three(a, b, three_position);
    sort_three(a);
    pa(a, b);
    ra(a);
}

/* To sort four numbers, first three numbers of the stack should be sorted and to 
   do that correctly fourth number shouldn't be in the stack a while sorting three 
   numbers in stack a. Therefore, fourth number should be pushed to stack b but it
   has to be done with the lowest number of instructions in order to not exceed the 
   instruction limit. This function checks the distance or position of the fourth 
   number of the list, which is the biggest number in the stack, and execute the
   lowest number of instructions to push it to the stack b. */
void rotate_three_for_three(t_stack **a, t_stack **b, int three_position)
{
    int i;
    
    i = 0;
    if (three_position <= 2)
    {
        while (i < three_position)
        {
            ra(a);
            i++;
        }
    }
    else
    {
        while (i < (4 - three_position))
        {
            rra(a);
            i++;
        }
    }
    pb(a, b);
}
