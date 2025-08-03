/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:08 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:11:12 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list arg)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'c')
		printed_chars += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		printed_chars += print_s(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		printed_chars += print_di(va_arg(arg, int));
	else if (c == 'u')
		printed_chars += print_u(va_arg(arg, unsigned int));
	else if (c == 'p')
		printed_chars += print_p(va_arg(arg, unsigned long));
	else if (c == 'x')
		printed_chars += print_x(va_arg(arg, unsigned int), false);
	else if (c == 'X')
		printed_chars += print_x(va_arg(arg, unsigned int), true);
	else if (c == '%')
		printed_chars += ft_putchar('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			printed_chars;

	printed_chars = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_chars += check_type(*format, arg);
		}
		else
			printed_chars += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (printed_chars);
}
