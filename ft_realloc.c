/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:11:44 by mpascual          #+#    #+#             */
/*   Updated: 2023/05/23 16:15:46 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_realloc(void *src, size_t old_len, size_t new_len)
{
	void	*res;

	res = malloc(new_len);
	ft_memcpy(res, src, old_len);
	if (src)
		free (src);
	return (res);
}

