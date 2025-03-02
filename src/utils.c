/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:46:00 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:53:24 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_error(void)
{
	ft_printf(2, "Error\n");
	exit(1);
}

int	find_min_index(int *items, int size)
{
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	while (i < size)
	{
		if (items[i] < items[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	find_max_index(int *items, int size)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i < size)
	{
		if (items[i] > items[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
