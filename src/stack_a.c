/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:40:52 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:51:42 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (!stack_a->items)
		return ;
	temp = stack_a->items[0];
	stack_a->items[0] = stack_a->items[1];
	stack_a->items[1] = temp;
	ft_printf(1, "sa\n");
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	int	i;

	i = stack_a->size;
	if (stack_b->size == 0)
		return ;
	while (i > 0)
	{
		stack_a->items[i] = stack_a->items[i - 1];
		i--;
	}
	stack_a->items[0] = stack_b->items[0];
	stack_a->size++;
	stack_b->size--;
	i = 0;
	while (i < stack_b->size)
	{
		stack_b->items[i] = stack_b->items[i + 1];
		i++;
	}
	ft_printf(1, "pa\n");
}

void	ra(t_stack *stack_a)
{
	int	i;
	int	first;

	first = stack_a->items[0];
	i = 0;
	while (i < stack_a->size)
	{
		stack_a->items[i] = stack_a->items[i + 1];
		i++;
	}
	stack_a->items[stack_a->size - 1] = first;
	ft_printf(1, "ra\n");
}

void	rra(t_stack *stack_a)
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
	ft_printf(1, "rra\n");
}
