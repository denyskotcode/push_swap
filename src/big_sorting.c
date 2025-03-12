/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:25:17 by dkot              #+#    #+#             */
/*   Updated: 2025/03/12 18:47:04 by dkot             ###   ########.fr       */
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

void sort_big(t_list **a, t_list **b, int count)
{
	int avg;

	while (ft_lstsize(*a) > 3 && !is_sorted(*a)) {

	}
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

int	move_from_b_to_a(t_list **a, t_list **b)
{
	t_cost	*cheapest;
	while (*b)
	{

		free(cheapest);
	}
	

}

void	move_to_top(t_list **a)
{
	while (!is_sorted(*a))
	{
		ra(a);
	}
}

t_cost	*get_cheapest(t_list *a, t_list *b, int size)
{
	t_cost	*cheapest;
	t_cost	*tmp;
	t_list	*tmp_b;



}
t_cost	*calculate_cost(t_list *stack_a, t_list *stack_b, \
	int value, int size)
{
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
	return (NULL);
	cost->value = value;
	cost->ra = 0;
	cost->rra = 0;
	cost->rb = 0;
	cost->rrb = 0;
	cost->sum = 0;
	get_b_moves(stack_b, value, cost, size);
	get_a_moves(stack_a, value, cost);
	get_total_moves(cost);
	return (cost);
}

static void	get_b_moves(t_list *stack_b, int value, t_cost *cost, int size)
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

static void	get_a_moves(t_list *stack_a, int value, t_cost *cost)
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