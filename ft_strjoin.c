/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:17:27 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/20 19:51:06 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*nstr;
	unsigned int	i[2];

	i[0] = 0;
	i[1] = 0;
	if (!s1 || !s2)
		return (NULL);
	nstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (nstr == NULL)
		return (NULL);
	else
	{
		while (s1[i[0]] != 0)
		{
			nstr[i[0]] = s1[i[0]];
			i[0]++;
		}
		while (s2[i[1]] != 0)
		{
			nstr[i[0] + i[1]] = s2[i[1]];
			i[1]++;
		}
		nstr[i[0] + i[1]] = '\0';
		return (nstr);
	}
}
