/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:54:20 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 13:57:09 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void px(t_list **a, t_list **b)
{
    t_list *temp;

    if (!*b)
        return;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
}

void pa(t_list **a, t_list **b)
{
	px(a,b);
	ft_printf("pa\n");
}

void pb(t_list **a, t_list **b)
{
	px(b,a);
	ft_printf("pb\n");
}