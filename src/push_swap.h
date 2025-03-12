/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:53:19 by dkot              #+#    #+#             */
/*   Updated: 2025/03/12 20:01:00 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/libftprintf/ft_printf.h"

typedef struct s_move_cost
{
	int	value;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
}	t_move_cost;

int			is_valid_number(const char *str);
int			check_number(const char *str, int i, int sign);
int			process_arg(char *arg, int *count);
int			count_numbers(char **argv);
void		ft_free_split(char **split);
int			parse_argument(char *arg, long long *numbers, int *index);
long long	*parse_numbers(char **argv, int argc, int *total_count);
int			has_duplicates(long long *numbers, int total_count);
int			check_duplicates(char **argv, int argc);
t_list		*init_stack_a(int argc, char **argv);
int			process_argument(char *arg, t_list **stack_a);
void		free_stacks(t_list **stack_a, t_list **stack_b);
void		sx(t_list **x);
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		px(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		rx(t_list **x);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rrx(t_list **x);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);
void        sort_two(t_list **a);
void        sort_three(t_list **a);
void	move_from_a_to_b(t_list	**a, t_list	**b);
void sort_big(t_list **a, t_list **b);
void push_swap(t_list **a, t_list **b, int count);
void    get_b_moves(t_list *stack_b, int value, t_move_cost *cost, int size);
void    get_a_moves(t_list *stack_a, int value, t_move_cost *cost);
void    determine_moves(t_move_cost *cost, int ra_rrb, int rra_rb);
void    get_total_moves(t_move_cost *cost);
t_move_cost *calculate_cost(t_list *stack_a, t_list *stack_b, int value, int size);
void    execute_moves(t_move_cost *cheapest, t_list **stack_a, t_list **stack_b);
void    copy_moves_data(t_move_cost *dest, t_move_cost *src);
int     ft_max(int a, int b);
int     get_min(int a, int b, int c, int d);
int     ft_lstmin(t_list *stack);
int     ft_lstmax(t_list *stack);
t_move_cost *get_cheapest(t_list *stack_a, t_list *stack_b, int size);
int     is_sorted(t_list *stack);
int     get_avg(t_list *stack);
void    sort_big(t_list **a, t_list **b);
void    move_from_a_to_b(t_list **a, t_list **b);
int     move_from_b_to_a(t_list **a, t_list **b);
void    move_to_top(t_list **a);

#endif
