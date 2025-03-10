/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:52 by dkot              #+#    #+#             */
/*   Updated: 2025/03/10 14:15:01 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_lstclear1(t_list **lst, void (*del)(void *))
{
    t_list *current = *lst;
    t_list *next;
    while (current)
    {
        next = current->next;
        del(current->content); // Frees the int*
        free(current);         // Frees the t_list node
        current = next;
    }
    *lst = NULL;
}

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

	t_list *a;
	t_list *test;
	a = init_stack_a(argc, argv);
	test = a;
	while (test != NULL)
	{
		ft_printf("%d number\n", *(int *)(test->content));
		test = test->next;
	}
    ft_lstclear(&a, free);

	return (0);
}
