/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:36:34 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 17:17:12 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_list **x)
{
	t_list *last;
	t_list *second_last;

	if (!*x || !(*x)->next)
		return;
	last = ft_lstlast(*x);
	second_last = *x;
	while (second_last->next != last)
		second_last = second_last->next;
	last->next = *x;
	*x = last;
	second_last->next = NULL;
}

void	rra(t_list **a)
{
	rrx(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	rrx(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
