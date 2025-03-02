/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:28:36 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:50:23 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp_a;
	int	temp_b;

	if (!stack_a->items || !stack_b->items)
		return ;
	temp_a = stack_a->items[0];
	temp_b = stack_b->items[0];
	stack_a->items[0] = stack_a->items[1];
	stack_b->items[0] = stack_b->items[1];
	stack_a->items[1] = temp_a;
	stack_b->items[1] = temp_b;
	ft_printf(1, "ss\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	first;
	int	last;

	i = 0;
	first = stack_a->items[0];
	last = stack_b->items[0];
	while (i < stack_a->size)
	{
		stack_a->items[i] = stack_a->items[i + 1];
		i++;
	}
	stack_a->items[stack_a->size - 1] = first;
	i = 0;
	while (i < stack_b->size)
	{
		stack_b->items[i] = stack_b->items[i + 1];
		i++;
	}
	stack_b->items[stack_b->size - 1] = last;
	ft_printf(1, "rr\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	last;

	i = stack_a->size - 1;
	last = stack_a->items[stack_a->size - 1];
	while (i >= 0)
	{
		stack_a->items[i] = stack_a->items[i - 1];
		i--;
	}
	stack_a->items[0] = last;
	i = stack_b->size - 1;
	last = stack_b->items[stack_b->size - 1];
	while (i >= 0)
	{
		stack_b->items[i] = stack_b->items[i - 1];
		i--;
	}
	stack_b->items[0] = last;
	ft_printf(1, "rrr\n");
}
