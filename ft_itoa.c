/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:45:01 by mpascual          #+#    #+#             */
/*   Updated: 2025/06/12 15:42:42 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nblen(long nb, int base_len)
/*
**  ft_nblen doesn't count for the negative sing if the number is < 0
**  It returns ONLY the number of DIGITS
*/
{
	long	n_digits;

	n_digits = 1;
	if (nb < 0)
		nb *= -1;
	while (nb >= base_len)
	{
		n_digits++;
		nb /= base_len;
	}
	return (n_digits);
}

static void	ft_strrev(char *s)
{
	char	*s_end;
	char	c;

	s_end = s + ft_strlen(s) - 1;
	while (s < s_end)
	{
		c = *s;
		*s++ = *s_end;
		*s_end-- = c;
	}
}

char	*convert_itoa(int nbr, char *str, unsigned int neg)
{
	unsigned int	i;

	i = 0;
	while (nbr >= 10)
	{
		str[i++] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	str[i++] = (nbr % 10 + '0');
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	neg;

	neg = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		neg = 1;
	}
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(ft_nblen(nbr, 10) * sizeof(char) + neg + 1);
	if (str == NULL)
		return (NULL);
	convert_itoa(nbr, str, neg);
	ft_strrev(str);
	return (str);
}
