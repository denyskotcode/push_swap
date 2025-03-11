/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:01:44 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 17:15:48 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_list **x)
{
	t_list	*first;
	t_list	*last;

	if (!*x || !(*x)->next)
		return ;
	first = *x;
	*x = first->next;
	last = ft_lstlast(*x);
	last->next = first;
	first->next = NULL;
}

void	ra(t_list **a)
{
	rx(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	rx(b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rx(a);
	rx(b);
	ft_printf("rr\n");
}
