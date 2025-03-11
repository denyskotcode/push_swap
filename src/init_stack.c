/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:35:03 by dkot              #+#    #+#             */
/*   Updated: 2025/03/11 15:43:47 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int process_argument(char *arg, t_list **stack_a)
{
    char **split;
    int j;
    t_list *new_node;
    int *num;

    split = ft_split(arg, ' ');
    if (!split)
        return (-1);
    j = 0;
    while (split[j])
    {
        if (!is_valid_number(split[j]))
        {
            ft_free_split(split);
            return (-1);
        }
        num = malloc(sizeof(int));
        if (!num)
        {
            ft_free_split(split);
            return (-1);
        }
        *num = ft_atoi(split[j]);
        new_node = ft_lstnew(num);
        if (!new_node)
        {
            free(num);
            ft_free_split(split);
            return (-1);
        }
        ft_lstadd_back(stack_a, new_node);
        j++;
    }
    ft_free_split(split);
    return (0);
}

t_list *init_stack_a(int argc, char **argv)
{
    t_list *stack_a = NULL;
    int i = 1;

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
