/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:24:08 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/20 16:03:10 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void	free_double_pointer(void **double_p)
{
	size_t	i;

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

static void	free_triple_pointer(void ***triple_p)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (triple_p)
	{
		while (triple_p[i])
		{
			j = 0;
			while (triple_p[i][j])
			{
				free(triple_p[i][j]);
				j++;
			}
			free(triple_p[i]);
			i++;
		}
		free(triple_p);
	}
}

void	ft_free(const char *format, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	va_start(args, format);
	if (!format)
	{
		va_end(args);
		return ;
	}
	while (format[i])
	{
		if (format[i] == 's')
			free(va_arg(args, void *));
		else if (format[i] == 'd')
			free_double_pointer(va_arg(args, void **));
		else if (format[i] == 't')
			free_triple_pointer(va_arg(args, void ***));
		i++;
	}
	va_end(args);
}
