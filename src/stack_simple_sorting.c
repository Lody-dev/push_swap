/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_simple_sorting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:41:00 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:52:40 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_sort_three(t_stack *stack)
{
	int	first;
	int	middle;
	int	last;

	first = stack->items[0];
	middle = stack->items[1];
	last = stack->items[2];
	if (first > middle && middle < last && first > last)
		ra(stack);
	else if (first < middle && middle > last && first > last)
		rra(stack);
	else if (first > middle && middle < last && last > first)
		sa(stack);
	else if (first < middle && middle > last && last > first)
	{
		rra(stack);
		sa(stack);
	}
	else if (first > middle && middle > last && last < first)
	{
		ra(stack);
		sa(stack);
	}
}

void	stack_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min_index(stack_a->items, stack_a->size);
	if (min == 1)
		sa(stack_a);
	else if (min == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (min == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	stack_sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	stack_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;

	i = -1;
	while (++i < 2)
	{
		min = find_min_index(stack_a->items, stack_a->size);
		if (min <= 2)
			while (min-- > 0)
				ra(stack_a);
		else
			while (min++ <= stack_a->size - 1)
				rra(stack_a);
		pb(stack_a, stack_b);
	}
	stack_sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
