#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
    struct s_stack *next;
    struct s_stack *prev;
    int value;
    int position;
} t_stack;

/* count_and_error.c */
int number_counter(char *str);
void non_numeric_check(char *str);
void sign_check(char *str);
void duplicate_check(int *arr, int total_number);
void max_check(long int nbr, int *arr);

/* parser.c */
void parser(int *arr, char **str);
void ft_split(char *str, int *arr, int *nbr);
int ft_strncpy(char *str1, int size, int *arr);
int ft_atoi(char *str, int *arr);

/* create_and_sort_stack */
void create_and_sort_stack(t_stack **a, t_stack **b, int *arr, int total);
t_stack *find_last(t_stack *a);
void create_stack(t_stack **a, int *arr, int *pos);

/* utils.c */
void free_and_exit(int *arr, int *cpy_arr);
void sorted_check(int *arr, int total);
int *find_positions(int *arr, int *cpy_arr, int total);
void sort_cpy_arr(int *cpy_arr, int total);
int *cpy_and_sort_array(int *arr, int total);

/* push_swap.c */
void push_swap(t_stack **a, t_stack **b, int total);
int check_b_empty(t_stack **a, t_stack **b);

/* radix.c */
void ra(t_stack **a);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void sa(t_stack **a);
void rra(t_stack **a);

/* simple_sort.c */
void simple_sort(t_stack **a, t_stack **b, int total);
void sort_two(t_stack **a);
void sort_four(t_stack **a, t_stack **b);
void rotate_three_for_three(t_stack **a, t_stack **b, int three_position);

/* sort_three.c */
void sort_three(t_stack **a);
int find_zero(t_stack *a);
int find_one(t_stack *a);

/* sort_five.c */
void sort_five(t_stack **a, t_stack **b);
void rotate_push_three(t_stack **a, t_stack **b, int three_position);
void rotate_push_four(t_stack **a, t_stack **b, int four_position);
int find_three(t_stack *a);
int find_four(t_stack *a);

#endif