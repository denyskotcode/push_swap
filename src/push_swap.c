/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:52 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 17:17:42 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int count;

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
	t_list *b;
	// t_list *test_a;
	// t_list *test_b;


	a = init_stack_a(argc, argv);
	b = NULL;
	if (count == 2)
		sort_two(&a);
	else if (count == 3)
		sort_three(&a);
	
	// test_a = a;
	// test_b = b;
	// while (test_a != NULL)
	// {
	// 	ft_printf("%d a\n", *(int *)(test_a->content));
	// 	test_a = test_a->next;
	// }
	// while (test_b != NULL)
	// {
	// 	ft_printf("%d b\n", *(int *)(test_b->content));
	// 	test_b = test_b->next;
	// }
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
