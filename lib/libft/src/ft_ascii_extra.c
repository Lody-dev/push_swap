/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viaremko <viaremko@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:05:40 by viaremko          #+#    #+#             */
/*   Updated: 2025/02/17 13:06:19 by viaremko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nlibft.h"

// Should be Static for Francinette

int	ft_isspace(int c)
{
	return ((c == ' ') || (9 <= c && c <= 13));
}

// Should be Static for Francinette

int	ft_sign(char c)
{
	return (c == '-' || c == '+');
}
