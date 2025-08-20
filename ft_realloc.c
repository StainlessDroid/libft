/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:41:41 by mapascua          #+#    #+#             */
/*   Updated: 2025/08/20 12:42:10 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t old_len, size_t new_len)
{
	void	*res;

	res = malloc(new_len);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, src, old_len);
	if (src)
		free (src);
	return (res);
}
