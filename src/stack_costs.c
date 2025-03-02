/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:34:16 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:52:17 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*calc_costs_a(t_stack *stack_a, t_stack *stack_b, int *targets)
{
	int	i;
	int	*costs;

	i = -1;
	stack_a->median = (stack_a->size) / 2;
	stack_b->median = (stack_b->size) / 2;
	costs = (int *)malloc(stack_a->size * sizeof(int));
	while (++i < stack_a->size)
	{
		if (i <= stack_a->median && targets[i] <= stack_b->median)
			costs[i] = i + targets[i];
		else if (i <= stack_a->median && targets[i] > stack_b->median)
			costs[i] = i + (stack_b->size - targets[i]);
		else if (i > stack_a->median && targets[i] > stack_b->median)
			costs[i] = (stack_a->size - i) + (stack_b->size - targets[i]);
		else if (i > stack_a->median && targets[i] <= stack_b->median)
			costs[i] = (stack_a->size - i) + targets[i];
	}
	return (costs);
}

int	*calc_costs_b(t_stack *stack_b, t_stack *stack_a, int *targets)
{
	int	i;
	int	*costs;

	i = -1;
	stack_a->median = (stack_a->size) / 2;
	stack_b->median = (stack_b->size) / 2;
	costs = (int *)malloc(stack_b->size * sizeof(int));
	while (++i < stack_b->size)
	{
		if (i <= stack_b->median && targets[i] <= stack_a->median)
			costs[i] = i + targets[i];
		else if (i <= stack_b->median && targets[i] > stack_a->median)
			costs[i] = i + (stack_a->size - targets[i]);
		else if (i > stack_b->median && targets[i] > stack_a->median)
			costs[i] = (stack_b->size - i) + (stack_a->size - targets[i]);
		else if (i > stack_b->median && targets[i] <= stack_a->median)
			costs[i] = (stack_b->size - i) + targets[i];
	}
	return (costs);
}
