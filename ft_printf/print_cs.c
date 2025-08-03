/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:40 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:11:42 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	print_s(char *str)
{
	int		printed_chars;

	if (!str)
		str = "(null)";
	printed_chars = ft_putstr(str);
	return (printed_chars);
}
