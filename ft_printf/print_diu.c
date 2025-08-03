/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:51 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:11:52 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nbrlen(long nb, int base_len)
/*	Returns the number of digits in a number
	THE SIGN IS IGNORED
*/
{
	unsigned int	n_digits;

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

int	ft_putnbr_u(unsigned int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb >= 10)
	{
		printed_chars += ft_putnbr_u(nb / 10);
		printed_chars += ft_putchar(nb % 10 + '0');
	}
	else
		printed_chars += ft_putchar(nb + '0');
	return (printed_chars);
}

int	print_di(int nb)
{
	int		len;

	len = ft_nbrlen(nb, 10);
	if (nb < 0)
		len++;
	ft_putnbr_fd(nb, 1);
	return (len);
}

int	print_u(unsigned int nb)
{
	int		len;

	len = ft_nbrlen(nb, 10);
	ft_putnbr_u(nb);
	return (len);
}
