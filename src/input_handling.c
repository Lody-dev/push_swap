/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:21:49 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/28 15:54:37 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*one_line_arguments(int args_count, char **args_values)
{
	char	*args_line;
	char	*temp;
	int		i;

	i = 1;
	args_line = ft_strdup("");
	if (args_count == 1)
		exit(1);
	else
	{
		while (i < args_count)
		{
			temp = args_line;
			args_line = ft_strjoin(args_line, args_values[i]);
			ft_memclean(temp);
			temp = args_line;
			args_line = ft_strjoin(args_line, " ");
			ft_memclean(temp);
			i++;
		}
	}
	return (args_line);
}

char	**input_handler(int args_count, char **args_values)
{
	char	*line;
	char	**split_output;

	if (args_count == 1)
		exit(1);
	line = one_line_arguments(args_count, args_values);
	split_output = ft_split(line, 32);
	ft_memclean(line);
	return (split_output);
}

int	is_valid_argument(const char *arg)
{
	if (ft_sign(*arg))
		arg++;
	if (!*arg)
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

int	stack_check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->items[i] == stack->items[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
