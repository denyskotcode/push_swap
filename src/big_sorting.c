/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:25:17 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 17:39:34 by dkot             ###   ########.fr       */
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

int get_avg(t_list *stack, int size)
{
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

void sort_big(t_list **a, t_list **b, int count)
{
	int avg;

	avg = get_avg(*a, count);
	while (ft_lstsize(*a) > 3 && !is_sorted(*a)) {
		if (*(int *)(*a)->content <= avg)
			pb(a, b);
		else
			ra(a);
	}
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 2)
		sort_two(a);
}