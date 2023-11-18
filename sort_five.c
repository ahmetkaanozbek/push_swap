#include "push_swap.h"

/* This function sorts 5 numbers in max 12 number of instructions. To do that
   correctly, first, it finds the biggest and the second biggest number of the 
   list and push it to the stack b to correctly sort 3 numbers in stack a. To 
   keep the lowest number of instructions, first, the second biggest number of 
   the list is pushed to stack b to not to swap(sa()) the biggest and the second 
   biggest number of the list when they are pushed to stack a after three numbers
   are sorted. */
void sort_five(t_stack **a, t_stack **b)
{
    int three_position;
    int four_position;

    three_position = find_three(*a);
    rotate_push_three(a, b, three_position);
    four_position = find_four(*a);
    rotate_push_four(a, b, four_position);
    sort_three(a);
    pa(a, b);
    pa(a, b);
    ra(a);
    ra(a);
}

/* With the distance of the second biggest number of the list to the head of 
   the list, it executes ra() or rra(). If the distance is more than or equal 
   to 2 it executes ra() to put it to the head of the list then the function 
   could execute pb() to put it to the top of the stack b. If the distance is more
   than 2 then the function executes rra() for several times to put it to the 
   head of the list or top of the stack a */
void rotate_push_three(t_stack **a, t_stack **b, int three_position)
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
        while (i < (5 - three_position))
        {
            rra(a);
            i++;
        }
    }
    pb(a, b);
}

/* After pushing the second biggest number of the list to the stack b
   this function put the biggest number of the list to the head of stack
   a then it pushes the biggest number to the top of the stack b */
void rotate_push_four(t_stack **a, t_stack **b, int four_position)
{
    int i;

    i = 0;
    if (four_position <= 2)
    {
        while (i < four_position)
        {
            ra(a);
            i++;
        }
    }
    else
    {
        while (i < (4 - four_position))
        {
            rra(a);
            i++;
        }
    }
    pb(a, b);
}

/* It finds the fourth biggest number which is 3 as position then it finds 
   the distance of it to the head of the list. It finds the distance due to execute 
   lowest number of instructions. */
int find_three(t_stack *a)
{
    int position;

    position = 0;
    while (a->position != 3)
    {
        a = a->next;
        position++;
    }
    return (position);
}

/* It finds the biggest number of the list which is 4 as position then it 
   finds the distance of it to the head of the list. It finds the distance due 
   to execute lowest number of instructions. */
int find_four(t_stack *a)
{
    int position;

    position = 0;
    while (a->position != 4)
    {
        a = a->next;
        position++;
    }
    return (position);
}