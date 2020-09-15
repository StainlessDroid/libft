/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:49:38 by mpascual          #+#    #+#             */
/*   Updated: 2020/09/15 18:50:29 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_nbrlen(int nb, int base_len)
{
    unsigned int n_digits;
    bool         neg;

    neg = nb < 0 ? TRUE : FALSE;
    n_digits = 0;
    while (nb / base_len > 0)
    {
        n_digits++;
        nb /= base_len;
    }
    if (neg)
        n_digits++;
    return (n_digits);
}
