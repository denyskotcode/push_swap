/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:38:51 by dkot              #+#    #+#             */
/*   Updated: 2025/03/12 21:48:05 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstmin(t_list *stack)
{
	int	min;
	int	current;

	if (stack == NULL)
		return (0);
	min = *(int *)stack->content;
	stack = stack->next;
	while (stack)
	{
		current = *(int *)stack->content;
		if (current < min)
			min = current;
		stack = stack->next;
	}
	return (min);
}

int	ft_lstmax(t_list *stack)
{
	int	max;
	int	current;

	if (stack == NULL)
		return (0);
	max = *(int *)stack->content;
	stack = stack->next;
	while (stack)
	{
		current = *(int *)stack->content;
		if (current > max)
			max = current;
		stack = stack->next;
	}
	return (max);
}
