#include "push_swap.h"

/* To sort three numbers there should be 3 number of instructions max and
   to achieve that every possible formation of three numbers should be 
   considered separately. There are 6 different formation of three numbers.
   To sort them correctly this function executes different instructions for
   5 different possibilities because one formation is already sorted. First, 
   it finds the position of 0 and 1 and checks for possibilities based on this. */
void sort_three(t_stack **a)
{
    int zero_position;
    int one_position;

    zero_position = find_zero(*a);
    one_position = find_one(*a);
    if (zero_position == 1 && one_position == 0)
        sa(a);
    else if (zero_position == 1 && one_position == 2)
        ra(a);
    else if (zero_position == 0 && one_position == 2)
    {
        sa(a);
        ra(a);
    }
    else if (zero_position == 2 && one_position == 0)
        rra(a);
    else if (zero_position == 2 && one_position == 1)
    {
        sa(a);
        rra(a);
    }
}

/* This function finds the position or the distance of the lowest number of 
   the list to the head of the list. The lowest number of the list is a->position=0 */
int find_zero(t_stack *a)
{
    int position;

    position = 0;
    while (a->position != 0)
    {
        position++;
        a = a->next;
    }
    return (position);
}

/* This function finds the position or the distance of the second lowest 
   number of the list to the head of the list. The second lowest number of
   the list is a->position=1 */
int find_one(t_stack *a)
{
    int position;

    position = 0;
    while (a->position != 1)
    {
        position++;
        a = a->next;
    }
    return (position);
}