#include "push_swap.h"

/* It rotates stack a. Shifts up all elements of stack a by 1. The first element 
   becomes the last one */
void ra(t_stack **a)
{
    t_stack *last;

    if ((*a)->next == NULL)
        return ;
    last = *a;
    while (last->next != NULL)
        last = last->next;
    last->next = *a;
    *a = (*a)->next;
    ((*a)->prev)->next = NULL;
    ((*a)->prev)->prev = last;
    (*a)->prev = NULL;
    write(1, "ra\n", 3);
}

/* It takes the first element at the top of a and put it at the top of b */
void pb(t_stack **a, t_stack **b)
{
    t_stack *first_a;

    first_a = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    if (*b == NULL)
    {
        *b = first_a;
        (*b)->prev = NULL;
        (*b)->next = NULL;
    }
    else
    {
        first_a->next = *b;
        (*b)->prev = first_a;
        *b = first_a;
    }
    write(1, "pb\n", 3);
}

/* It takes the first element at the top of b and put it at the top of a */
void pa(t_stack **a, t_stack **b)
{
    t_stack *first_b;

    if (*b == NULL)
        return ;
    first_b = *b;
    (*b) = (*b)->next;
    if (*a == NULL)
    {
        *a = first_b;
        (*a)->prev = NULL;
        (*a)->next = NULL;
    }
    else
    {
        first_b->prev = NULL;
        first_b->next = *a;
        (*a)->prev = first_b;
        *a = first_b;
    }
    write(1, "pa\n", 3);
}

/* It swaps the first 2 elements at the top of stack a */
void sa(t_stack **a)
{
    t_stack *second;
    t_stack *first;

    first = *a;
    second = (*a)->next;
    first->next = second->next;
    first->prev = second;
    second->next = first;
    second->prev = NULL;
    *a = second;
    if (first->next != NULL)
        (first->next)->prev = first;
    write(1, "sa\n", 3);
}

/* It shifts down all elements of stack a by 1. The last element becomes 
   the first one */
void rra(t_stack **a)
{
    t_stack *last;

    last = *a;
    while (last->next != NULL)
        last = last->next;
    (last->prev)->next = NULL;
    last->prev = NULL;
    last->next = *a;
    (*a)->prev = last;
    *a = last;
    write(1, "rra\n", 4);
}