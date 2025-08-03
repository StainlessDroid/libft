/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapascua <mapascua@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:21 by mapascua          #+#    #+#             */
/*   Updated: 2025/07/04 16:11:24 by mapascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_putchar(char c);
int				ft_putstr(const char *str);
int				check_type(const char c, va_list arg);
int				print_s(char *str);
unsigned int	ft_nbrlen(long nb, int base_len);
int				print_di(int nb);
int				print_u(unsigned int nb);
int				print_p(unsigned long ptr);
int				print_x(unsigned int nb, bool mayus);
int				ft_putnbr_hex(unsigned long nb, bool mayus);
int				ft_putnbr_u(unsigned int nb);

#endif
