/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:04:56 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:52:30 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	choose_rotation_a(t_stack *stack_a, int value)
{
	int	i;

	i = -1;
	if (value <= stack_a->median)
		while (++i < value)
			ra(stack_a);
	else
		while (++i < (stack_a->size - value))
			rra(stack_a);
}

void	choose_rotation_b(t_stack *stack_b, int value)
{
	int	i;

	i = -1;
	if (value <= stack_b->median)
		while (++i < value)
			rb(stack_b);
	else
		while (++i < (stack_b->size - value))
			rrb(stack_b);
}

void	stack_rotator_a(t_stack *stack_a, t_stack *stack_b, \
						int *targets, int *costs)
{
	int	best;

	best = find_min_index(costs, stack_a->size);
	choose_rotation_a(stack_a, best);
	choose_rotation_b(stack_b, targets[best]);
	pb(stack_a, stack_b);
}

void	stack_rotator_b(t_stack *stack_b, t_stack *stack_a, \
						int *targets, int *costs)
{
	int	best;

	best = find_min_index(costs, stack_b->size);
	choose_rotation_b(stack_b, best);
	choose_rotation_a(stack_a, targets[best]);
	pa(stack_b, stack_a);
}

void	stack_final_rotator_a(t_stack *stack_a)
{
	int	pos;

	pos = find_min_index(stack_a->items, stack_a->size);
	choose_rotation_a(stack_a, pos);
}
