/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:27:57 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 13:44:28 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_list **x)
{
	t_list *first;
	t_list *second;
	if (!*x || !(*x)->next)
		return;
	first = *x;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*x = second;
}
void	sa(t_list **a)
{
	sx(a);
	ft_printf("sa\n");
}
void	sb(t_list **b)
{
	sx(b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
    sx(a);
    sx(b);
    ft_printf("ss\n");
}