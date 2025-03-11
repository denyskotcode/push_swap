/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:53:19 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 15:43:42 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "../libs/libftprintf/ft_printf.h"

typedef struct	s_stack
{
	t_list	*top;
}   t_stack;

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
#endif
