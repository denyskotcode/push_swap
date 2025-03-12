/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:25:17 by dkot              #+#    #+#             */
/*   Updated: 2025/03/12 19:17:23 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_list *stack)
{
	while (stack && stack->next) {
		if (*(int *)stack->content > *(int *)stack->next->content)
			return 0;
		stack = stack->next;
	}
	return 1;
}

int get_avg(t_list *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (!stack || size == 0)
		return 0;
	int sum = 0;
	t_list *current = stack;
	while (current) {
		sum += *(int *)current->content;
		current = current->next;
	}
	return (sum / size);
}

void sort_big(t_list **a, t_list **b)
{
	move_from_a_to_b(a,b);
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 2)
		sort_two(a);
}

void	move_from_a_to_b(t_list	**a, t_list	**b)
{
	int	avg;
	int	list_size;

	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		avg = get_avg(*a);
		list_size = ft_lstsize(*a);
		while (list_size-- && ft_lstsize(*a) > 3 && !is_sorted(*a))
		{
			if (*(int *)(*a)->content < avg)
				pb(a, b);
			else
				ra(a);
		}
	}
}

// void	move_to_top(t_list **a)
// {
// 	while (!is_sorted(*a))
// 	{
// 		ra(a);
// 	}
// }
