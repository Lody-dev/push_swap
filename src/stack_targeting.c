/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_targeting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:30:54 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:52:52 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*find_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	lowest;
	int	*targets;

	i = -1;
	targets = (int *)malloc(stack_a->size * sizeof(int));
	while (++i < stack_a->size)
	{
		j = -1;
		lowest = MIN_INT;
		while (++j < stack_b->size)
		{
			if ((stack_b->items[j] < stack_a->items[i]) && \
				(stack_b->items[j] >= lowest))
			{
				lowest = stack_b->items[j];
				targets[i] = j;
			}
		}
		if (lowest == MIN_INT)
			targets[i] = find_max_index(stack_b->items, stack_b->size);
	}
	return (targets);
}

int	*find_targets_b(t_stack *stack_b, t_stack *stack_a)
{
	int	i;
	int	j;
	int	biggest;
	int	*targets;

	i = -1;
	targets = (int *)malloc(stack_b->size * sizeof(int));
	while (++i < stack_b->size)
	{
		j = -1;
		biggest = MAX_INT;
		while (++j < stack_a->size)
		{
			if ((stack_a->items[j] > stack_b->items[i]) && \
				(stack_a->items[j] <= biggest))
			{
				biggest = stack_a->items[j];
				targets[i] = j;
			}
		}
		if (biggest == MAX_INT)
			targets[i] = find_min_index(stack_a->items, stack_a->size);
	}
	return (targets);
}
