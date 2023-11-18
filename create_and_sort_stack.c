#include "push_swap.h"

/* This function finds the last node with using head of the list to link 
   newly created node to last node */
t_stack *find_last(t_stack *a)
{
    while (a->next != NULL)
        a = a->next;
    return (a);
}

/* It creates nodes. If there is no list which means if *a==NULL it creates a
   head for the list. If there is a head then it finds the last node and link it
   with the created node */
void create_stack(t_stack **a, int *arr, int *pos)
{
    t_stack *new;
    t_stack *last;

    new = malloc(sizeof(t_stack));
    new->next = NULL;
    new->value = *arr;
    new->position = *pos;
    if (*a == NULL)
    {
        new->prev = NULL;
        *a = new;
    }
    else
    {
        last = find_last(*a);
        last->next = new;
        new->prev = last;
    }
}

/* First, it calls function to create stack then it calls functions to sort 
   that created stack in ascending order. It also frees all the memories
   allocated by malloc */
void create_and_sort_stack(t_stack **a, t_stack **b, int *arr, int total)
{
    int *pos_arr;
    int i;
    t_stack *temp;

    i = 0;
    pos_arr = cpy_and_sort_array(arr, total);
    while (i < total)
    {
        create_stack(a, &arr[i], &pos_arr[i]);
        i++;
    }
    if (total <= 5)
        simple_sort(a, b, total);
    else
        push_swap(a, b, total);
    free(arr); 
    free(pos_arr);
    while (*a != NULL)
    {
        temp = (*a)->next;
        free(*a);
        *a = temp;
    }
}