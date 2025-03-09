/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:52 by dkot              #+#    #+#             */
/*   Updated: 2025/03/09 19:18:27 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	count;
	if (argc < 2)
	{
		ft_printf("Error! No arguments found\n");
		return (0);
	}
	count = count_numbers(argv);
    if (count == -1 || check_duplicates(argv, argc) == -1)
	{
        ft_printf("Error: Invalid input.\n");
		return (0);
    }
	ft_printf("%d", count);

	return (0);
}