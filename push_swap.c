/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:50:56 by mpascual          #+#    #+#             */
/*   Updated: 2022/08/07 15:27:35 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(int *stack)
{
	return (FALSE);
}

static void	error_exit(int flag)
{
	ft_printf("Error\n");
	if (flag == 1)
	{
		ft_printf("Wrong Arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (flag == 2)
	{
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int *A;
	int *B;

	if (argc != 2)
		error_exit(1);
	

	//parsing: Fill the stack A 
	//check if A is sorted, if it is, exit
	//check lenght of stack A, then assign the same amount of mem to B.
	//if len(A) <= 5 call small_sort() else, call big_sort()
	return (EXIT_SUCCESS);
}
