/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:19:18 by mapascua          #+#    #+#             */
/*   Updated: 2025/09/20 15:06:29 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strjoin_chain(size_t count, ...)
{
	size_t	i;
	char	*newstr;
	char	*tmp;
	va_list	args;

	i = 0;
	newstr = ft_strdup("");
	va_start(args, count);
	while (i < count)
	{
		tmp = ft_strjoin(newstr, va_arg(args, const char *));
		if (tmp == NULL)
		{
			va_end(args);
			return (NULL);
		}
		free(newstr);
		newstr = tmp;
		i++;
	}
	va_end(args);
	return (newstr);
}
