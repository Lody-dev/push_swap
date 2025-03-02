/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:46:06 by viaremko          #+#    #+#             */
/*   Updated: 2025/01/18 16:56:20 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	l_len;

	l_len = 0;
	while (lst)
	{
		lst = lst->next;
		l_len++;
	}
	return (l_len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
