/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:41:07 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:53:04 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_init(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->size = size - 1;
	stack_b->size = 0;
	stack_a->items = (int *)malloc(size * sizeof(int));
	stack_b->items = (int *)malloc(size * sizeof(int));
	stack_a->median = (stack_a->size) / 2;
	stack_b->median = 0;
	if (!stack_a->items || !stack_b->items)
		ft_error();
}

void	stack_fill(t_stack *stack, char **input)
{
	int		i;
	long	value;

	i = 0;
	while (i < stack->size)
	{
		value = ft_atol(input[i]);
		if (value < MIN_INT || value > MAX_INT)
			ft_error();
		stack->items[i] = value;
		i++;
	}
	i = 0;
	while (i <= stack->size)
		ft_memclean(input[i++]);
	free(input);
}

int	stack_check_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->items[i - 1] < stack->items[i])
			i++;
		else
			return (0);
	}
	return (1);
}

void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_check_sorted(stack_a))
	{
		if (stack_a->size == 2)
			sa(stack_a);
		else if (stack_a->size == 3)
			stack_sort_three(stack_a);
		else if (stack_a->size == 4)
			stack_sort_four(stack_a, stack_b);
		else if (stack_a->size == 5)
			stack_sort_five(stack_a, stack_b);
		else
			stack_cost_sort(stack_a, stack_b);
	}
	else
		exit(0);
}

void	stack_free(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->items)
		ft_memclean((char *)stack_a->items);
	if (stack_b->items)
		ft_memclean((char *)stack_b->items);
}
