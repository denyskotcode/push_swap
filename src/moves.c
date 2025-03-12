/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:36:04 by dkot              #+#    #+#             */
/*   Updated: 2025/03/12 20:01:54 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_b_moves(t_list *stack_b, int value, t_move_cost *cost, int size)
{
	cost->rb = 0;
	cost->rrb = size;
	while (stack_b && value != *(int *)stack_b->content)
	{
		stack_b = stack_b->next;
		cost->rb++;
	}
	cost->rrb = cost->rrb - cost->rb;
}

void	get_a_moves(t_list *stack_a, int value, t_move_cost *cost)
{
	int	min;
	int	max;
	int	size;

	min = ft_lstmin(stack_a);
	max = ft_lstmax(stack_a);
	size = ft_lstsize(stack_a);
	cost->ra = 0;
	cost->rra = ft_lstsize(stack_a);
	while (stack_a && stack_a->next)
	{
		cost->ra++;
		if (value > *(int *)stack_a->content \
			&& value < *(int *)stack_a->next->content)
			break ;
		if (*(int *)stack_a->content == max && value > max)
			break ;
		if (ft_lstsize(stack_a) != size && stack_a->next)
			if (*(int *)stack_a->next->content == min && value < min)
				break ;
		stack_a = stack_a->next;
	}
	cost->rra = cost->rra - cost->ra;
	if (!stack_a->next)
		cost->ra = 0;
}

void	determine_moves(t_move_cost *cost, int ra_rrb, int rra_rb)
{
	int	min;

	min = get_min(ra_rrb, rra_rb, \
		ft_max(cost->ra, cost->rb), ft_max(cost->rra, cost->rrb));
	if (min == ra_rrb)
	{
		cost->rra = 0;
		cost->rb = 0;
	}
	else if (min == rra_rb)
	{
		cost->ra = 0;
		cost->rrb = 0;
	}
	else if (min == ft_max(cost->ra, cost->rb))
	{
		cost->rra = 0;
		cost->rrb = 0;
	}
	else
	{
		cost->ra = 0;
		cost->rb = 0;
	}
	cost->total = min;
}

void	get_total_moves(t_move_cost *cost)
{
	int	ra_rrb;
	int	rra_rb;

	ra_rrb = cost->ra + cost->rrb;
	rra_rb = cost->rra + cost->rb;
	determine_moves(cost, ra_rrb, rra_rb);
}

t_move_cost	*calculate_cost(t_list *stack_a, t_list *stack_b, \
							int value, int size)
{
	t_move_cost	*cost;

	cost = malloc(sizeof(t_move_cost));
	if (!cost)
		return (NULL);
	cost->value = value;
	cost->ra = 0;
	cost->rra = 0;
	cost->rb = 0;
	cost->rrb = 0;
	cost->total = 0;
	get_b_moves(stack_b, value, cost, size);
	get_a_moves(stack_a, value, cost);
	get_total_moves(cost);
	return (cost);
}
void	execute_moves(t_move_cost *cheapest, t_list **stack_a, t_list **stack_b)
{
	while (cheapest->ra > 0 && cheapest->rb > 0)
	{
		rr(stack_a, stack_b);
		cheapest->ra--;
		cheapest->rb--;
	}
	while (cheapest->ra-- > 0)
		ra(stack_a);
	while (cheapest->rb-- > 0)
		rb(stack_b);
	while (cheapest->rra > 0 && cheapest->rrb > 0)
	{
		rrr(stack_a, stack_b);
		cheapest->rra--;
		cheapest->rrb--;
	}
	while (cheapest->rra-- > 0)
		rra(stack_a);
	while (cheapest->rrb-- > 0)
		rrb(stack_b);
	pa(stack_a, stack_b);
}
void	copy_moves_data(t_move_cost	*dest, t_move_cost *src)
{
	dest->value = src->value;
	dest->ra = src->ra;
	dest->rra = src->rra;
	dest->rb = src->rb;
	dest->rrb = src->rrb;
	dest->total = src->total;
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

int	ft_lstmin(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_lstmax(t_list *stack)
{
	int	max;

	max = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}

t_move_cost	*get_cheapest(t_list *stack_a, t_list *stack_b, int size)
{
	t_move_cost	*cheapest;
	t_move_cost	*tmp;
	t_list		*tmp_b;

	tmp_b = stack_b;
	cheapest = calculate_cost(stack_a, stack_b, *(int *)tmp_b->content, size);
	if (!cheapest)
		return (NULL);
	if (cheapest->total == 0)
		return (cheapest);
	while (tmp_b && cheapest->total > 5 + size / 100)
	{
		tmp = calculate_cost(stack_a, stack_b, *(int *)tmp_b->content, size);
		if (!tmp)
			return (free(cheapest), NULL);
		if (tmp->total < cheapest->total)
		{
			free(cheapest);
			cheapest = tmp;
		}
		else
			free(tmp);
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}