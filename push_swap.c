#include "push_swap.h"

/* This function sorts more than 5 numbers. It uses radix algorithm
   to sort them. Normally, radix algortihm needs 10 stacks for 10-base 
   numbers. However, instruction says the program can only use 2 stacks 
   to sort numbers. To overcome that problem, the program uses binary 
   versions of the given 10-base numbers. It sorts them based on 1s and
   0s in their binary versions. To do that it uses bitwise operators. 
   First, it finds the leftmost bit of the maximum number while doing that 
   it counts how many times should the program shift the numbers. For 
   example, if the maximum number is decimal 16 binary form of it would 
   be: 1 0 0 0 0 and the second biggest number's(15) binary form would 
   be: 1 1 1 1 so the biggest number's binary form always have the farthest  
   leftmost bit. Then, starting from the numbers rightmost bit the program 
   pushes 0s to stack b and keep 1s in stack a. After sorting each number's
   rightmost bit it increments bit's position by 1 until the rightmost bit of
   the biggest number and continue that sorting process in every bit position.*/
void push_swap(t_stack **a, t_stack **b, int total)
{
    int max_bit;
    int i;
    int j;

    max_bit = 0;
    i = 0;
    j = 0;
    while ((total - 1) >> max_bit)
        max_bit++;
    while (i < max_bit)
    {
        while (j < total)
        {
            if ((((*a)->position >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (check_b_empty(a, b))
            pa(a, b);
        j = 0;
        i++;
    }
}

/* It checks if the stack b is empty or not. If it is not it
   pushes numbers inside of it to the top of the stack a until 
   it becomes empty. */
int check_b_empty(t_stack **a, t_stack **b)
{
    if (*b == NULL)
        return (0);
    else
        return (1);
}