/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:40:57 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:51:21 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sb(t_stack *stack_b)
{
	int	temp;

	if (!stack_b->items)
		return ;
	temp = stack_b->items[0];
	stack_b->items[0] = stack_b->items[1];
	stack_b->items[1] = temp;
	ft_printf(1, "sb\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size;
	if (stack_a->size == 0)
		return ;
	while (i > 0)
	{
		stack_b->items[i] = stack_b->items[i - 1];
		i--;
	}
	stack_b->items[0] = stack_a->items[0];
	stack_b->size++;
	stack_a->size--;
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->items[i] = stack_a->items[i + 1];
		i++;
	}
	ft_printf(1, "pb\n");
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	last;

	last = stack_b->items[0];
	i = 0;
	while (i < stack_b->size)
	{
		stack_b->items[i] = stack_b->items[i + 1];
		i++;
	}
	stack_b->items[stack_b->size - 1] = last;
	ft_printf(1, "rb\n");
}

void	rrb(t_stack *stack_b)
{
	int	i;
	int	last;

	i = stack_b->size - 1;
	last = stack_b->items[stack_b->size - 1];
	while (i >= 0)
	{
		stack_b->items[i] = stack_b->items[i - 1];
		i--;
	}
	stack_b->items[0] = last;
	ft_printf(1, "rrb\n");
}
