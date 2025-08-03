/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:17:27 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/04 17:14:28 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*nstr;
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (nstr == NULL)
		return (NULL);
	while (*s1)
	{
		nstr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		nstr[i] = *s2;
		i++;
		s2++;
	}
	nstr[i] = '\0';
	return (nstr);
}
