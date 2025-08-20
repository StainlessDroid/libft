/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:38:21 by mapascua          #+#    #+#             */
/*   Updated: 2025/08/20 11:38:24 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digit(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		nbr;
	int		neg;
	int		current;

	nbr = 0;
	neg = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-' && neg == 0)
			neg = 1;
		str++;
	}
	current = get_digit(*str);
	while (current >= 0 && current < str_base)
	{
		nbr = nbr * str_base + current;
		str++;
		current = get_digit(*str);
	}
	if (neg)
		return (nbr * -1);
	else
		return (nbr);
}
