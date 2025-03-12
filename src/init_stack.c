/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:35:03 by dkot              #+#    #+#             */
/*   Updated: 2025/03/12 22:01:54 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_number_to_stack(char *num_str, t_list **stack_a)
{
	int		*num;
	t_list	*new_node;

	if (!is_valid_number(num_str))
		return (-1);
	num = malloc(sizeof(int));
	if (!num)
		return (-1);
	*num = ft_atoi(num_str);
	new_node = ft_lstnew(num);
	if (!new_node)
	{
		free(num);
		return (-1);
	}
	ft_lstadd_back(stack_a, new_node);
	return (0);
}

int	process_argument(char *arg, t_list **stack_a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (-1);
	j = 0;
	while (split[j])
	{
		if (add_number_to_stack(split[j], stack_a) == -1)
		{
			ft_free_split(split);
			return (-1);
		}
		j++;
	}
	ft_free_split(split);
	return (0);
}

t_list	*init_stack_a(int argc, char **argv)
{
	t_list		*stack_a;
	int			i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (process_argument(argv[i], &stack_a) == -1)
		{
			ft_lstclear(&stack_a, free);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}
