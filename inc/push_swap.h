/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsarmien <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:29:47 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/27 19:00:26 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PRE-PROCESSOR RULES */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDES */

# include "libft.h"

/* DEFINES */

# define MIN_INT -2147483648
# define MAX_INT 2147483647

/* STRUCTURES */

typedef struct s_stack
{
	int	size;
	int	median;
	int	*items;
}		t_stack;

/* MANDATORY PROTOTYPES */

// STACK_A FUNCTIONS

/**
 * @brief Swaps the first two numbers of the stack A.
 *
 * This function takes a pointer to a stack structure 't_stack' and
 * swaps the first two numbers of the stack.
 *
 * If the stack has fewer than two numbers, no operation is performed.
 * @param stack_a Pointer to 'stack_a'.
 * @return None
 */
void	sa(t_stack *stack_a);

/**
 * @brief Push the top element from the stack_b to the top on the stack_a.
 * @param stack_b Pointer to 'stack_b'.
 * @param stack_a Pointer to 'stack_a'.
 * @return None
 */
void	pa(t_stack *stack_b, t_stack *stack_a);

/**
 * @brief Shifts all the numbers of the stack A up by one position.
 *        The first element becomes the last one.
 * @param stack_a Pointer to 'stack_a'.
 * @return None
 */
void	ra(t_stack *stack_a);

/**
 * @brief Shifts all the numbers of the stack A down by one position.
 *        The last element becomes the first one.
 * @param stack_a Pointer to 'stack_a'.
 * @return None
 */
void	rra(t_stack *stack_a);

// STACK_B FUNCTIONS

/**
 * @brief Swaps the first two numbers of the stack B.
 *
 * This function takes a pointer to a stack structure 't_stack' and
 * swaps the first two numbers of the stack.
 *
 * If the stack has fewer than two numbers, no operation is performed.
 * @param stack_b Pointer to the list 'stack_b'.
 * @return None
 */
void	sb(t_stack *stack_b);

/**
 * @brief Push the top element from the stack_a to the top on the stack_b.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	pb(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Shifts all the numbers of the stack B up by one position.
 *        The first element becomes the last one.
 * @param stack_a Pointer to 'stack_b'.
 * @return None
 */
void	rb(t_stack *stack_b);

/**
 * @brief Shifts all the numbers of the stack B down by one position.
 *        The last element becomes the first one.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	rrb(t_stack *stack_b);

// STACK_AB FUNCTIONS

/**
 * @brief Swaps the top numbers from the both stacks.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	ss(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Shifts all the numbers of the both stacks up by one position.
 *        The first element becomes the last one.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	rr(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Shifts all the numbers of the both stacks down by one position.
 *        The last element becomes the first one.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	rrr(t_stack *stack_a, t_stack *stack_b);

// STACK GENERIC FUNCTIONS

/**
 * @brief Initialize the stacks with the given size
 * 		  and allocate the necessary memory.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	stack_init(t_stack *stack_a, t_stack *stack_b, int size);

/**
 * @brief Fills the stack with the input values received from the user.
 * @param stack Pointer to the stack.
 * @return None
 */
void	stack_fill(t_stack *stack, char **input);

/**
 * @brief Checks if the stack it's already sorted (we do nothing with it).
 * @param stack Pointer to the stack.
 * @return 0 if not sorted, 1 otherwise.
 */
int		stack_check_sorted(t_stack *stack);

/**
 * @brief It decide which function use to order up to five numbers in the stack.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	stack_sort(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Clears the memory allocated for the stacks.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	stack_free(t_stack *stack_a, t_stack *stack_b);

// INPUT HANDLING FUNCTIONS

char	*one_line_arguments(int args_count, char **args_values);
char	**input_handler(int args_count, char **args_values);
int		is_valid_argument(const char *arg);

/**
 * @brief Checks if the stack have duplicated numbers (not valid input).
 * @param stack Pointer to the stack.
 * @return 0 if no duplicates found, -1 otherwise.
 */
int		stack_check_duplicates(t_stack *stack);

// SIMPLE SORTING FUNCTIONS

/**
 * @brief Sort three numbers in the stack.
 * @param stack Pointer to the stack.
 * @return None
 */
void	stack_sort_three(t_stack *stack);

/**
 * @brief Sort four numbers in the stack.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	stack_sort_four(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sort five numbers in the stack.
 * @param stack_a Pointer to 'stack_a'.
 * @param stack_b Pointer to 'stack_b'.
 * @return None
 */
void	stack_sort_five(t_stack *stack_a, t_stack *stack_b);

// COMPLEX SORTING FUNCTIONS

int		*find_targets_a(t_stack *stack_a, t_stack *stack_b);
int		*find_targets_b(t_stack *stack_b, t_stack *stack_a);
int		*calc_costs_a(t_stack *stack_a, t_stack *stack_b, int *targets);
int		*calc_costs_b(t_stack *stack_b, t_stack *stack_a, int *targets);
void	choose_rotation_a(t_stack *stack_a, int value);
void	choose_rotation_b(t_stack *stack_b, int value);
void	stack_rotator_a(t_stack *stack_a, t_stack *stack_b, \
						int *targets, int *costs);
void	stack_rotator_b(t_stack *stack_b, t_stack *stack_a, \
						int *targets, int *costs);
void	stack_final_rotator_a(t_stack *stack_a);
void	stack_cost_sort(t_stack *stack_a, t_stack *stack_b);

// UTILS FUNCTIONS

/**
 * @brief Show an error message to the standard stderr.
 * @return -1
 */
int		ft_error(void);

/**
 * @brief Finds the index of the lowest number in the array.
 * @param items Array of integers.
 * @param size Size of the array.
 * @return Index of the lowest number.
 */
int		find_min_index(int *items, int size);

/**
 * @brief Finds the index of the biggest number in the array.
 * @param items Array of integers.
 * @param size Size of the array.
 * @return Index of the biggest number.
 */
int		find_max_index(int *items, int size);

#endif
