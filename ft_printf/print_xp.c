/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:12:04 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:12:05 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long nb, bool mayus)
/*
** requires a boolean parameter to specify if the alphabetic
** characters of the number are mayus
*/
{
	int		a;
	int		printed_chars;

	a = 87;
	printed_chars = 0;
	if (mayus)
		a = 55;
	if (nb >= 16)
	{
		printed_chars += ft_putnbr_hex(nb / 16, mayus);
		if (nb % 16 > 9)
			printed_chars += ft_putchar(nb % 16 + a);
		else
			printed_chars += ft_putchar(nb % 16 + '0');
	}
	else
	{
		if (nb % 16 > 9)
			printed_chars += ft_putchar(nb + a);
		else
			printed_chars += ft_putchar(nb + '0');
	}
	return (printed_chars);
}

int	print_x(unsigned int nb, bool mayus)
{
	int		printed_chars;

	printed_chars = ft_nbrlen(nb, 16);
	ft_putnbr_hex(nb, mayus);
	return (printed_chars);
}

int	print_p(unsigned long nb)
{
	int		printed_chars;

	printed_chars = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	printed_chars += ft_putstr("0x");
	printed_chars += ft_putnbr_hex(nb, false);
	return (printed_chars);
}
