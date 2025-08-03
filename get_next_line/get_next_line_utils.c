/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:16:05 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/10 21:43:02 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_mod(char *s, int len)
{
	char	*dest;

	dest = malloc (len + 1 * (sizeof (char)));
	if (!dest)
		return (NULL);
	dest[len] = 0;
	while (len && s[len - 1])
	{
		len --;
		dest[len] = s[len];
	}
	return (dest);
}

char	*ft_strjoin_mod(char *s1, char *s2)
/*	DO NOT USE OUTSIDE THIS PROJECT
	when the return value is assigned to the same pointer given as s1
	the function behaves like a realloc
*/
{
	char			*nstr;
	unsigned int	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (nstr == NULL)
		return (NULL);
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		nstr[i] = *s2;
		i++;
		s2++;
	}
	nstr[i] = '\0';
	free (s1);
	return (nstr);
}
