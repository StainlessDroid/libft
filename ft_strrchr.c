/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:39:12 by mapascua          #+#    #+#             */
/*   Updated: 2025/05/01 21:39:15 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	stop;

	stop = ft_strlen(s);
	s += ft_strlen(s);
	while (*s != (unsigned char)c)
	{
		if (stop-- == 0)
			return (NULL);
		s--;
	}
	return ((char *)s);
}
