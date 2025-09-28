/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:24:08 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/28 13:21:03 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void	free_null_terminated_double_ptr(void **double_p)
{
	int	i;

	i = 0;
	if (double_p)
	{
		while (double_p[i])
		{
			free(double_p[i]);
			i++;
		}
		free(double_p);
	}
}

static void	free_fix_lenght_double_ptr(void **double_p, int size)
{
	int	i;

	i = 0;
	if (double_p)
	{
		while (i < size)
		{
			free(double_p[i]);
			i++;
		}
		free(double_p);
	}
}

static void	free_null_terminated_triple_ptr(void ***triple_p)
{
	int	i;

	i = 0;
	if (triple_p)
	{
		while (triple_p[i])
		{
			free_null_terminated_double_ptr(triple_p[i]);
			i++;
		}
		free(triple_p);
	}
}

/*
 * Use the format specifier string to indicate the type and number 
 * of pointers to free:
 *   's' -> single pointer (void *)
 *   'd' -> double pointer, NULL-terminated (void **)
 *   'D' -> double pointer with length (requires extra size_t argument)
 *   't' -> triple pointer, NULL-terminated (void ***)
*/
void	ft_free(const char *format, ...)
{
	void	*ptr;
	va_list	args;

	va_start(args, format);
	while (format && *format)
	{
		if (*format == 's')
			free(va_arg(args, void *));
		else if (*format == 'd')
		{
			ptr = va_arg(args, void **);
			free_null_terminated_double_ptr(ptr);
		}
		else if (*format == 'D')
		{
			ptr = va_arg(args, void **);
			free_fix_lenght_double_ptr(ptr, va_arg(args, int));
		}
		else if (*format == 't')
		{
			ptr = va_arg(args, void ***);
			free_null_terminated_triple_ptr(ptr);
		}
		ptr = NULL;
		format++;
	}
	va_end(args);
}
