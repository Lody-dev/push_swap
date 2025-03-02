/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_complex_sorting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:57:32 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:52:00 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_cost_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*target_values;
	int	*costs;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		target_values = find_targets_a(stack_a, stack_b);
		costs = calc_costs_a(stack_a, stack_b, target_values);
		stack_rotator_a(stack_a, stack_b, target_values, costs);
		free(target_values);
		free(costs);
	}
	stack_sort_three(stack_a);
	while (stack_b->size > 0)
	{
		target_values = find_targets_b(stack_b, stack_a);
		costs = calc_costs_b(stack_b, stack_a, target_values);
		stack_rotator_b(stack_b, stack_a, target_values, costs);
		free(target_values);
		free(costs);
	}
	stack_final_rotator_a(stack_a);
}
