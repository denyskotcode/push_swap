/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:30:18 by dkot              #+#    #+#             */
/*   Updated: 2025/03/09 17:53:53 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_free_split(char **split)
{
    int i;

    if (!split)
        return;
    
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int	check_number(const char *str, int i, int sign)
{
	long long	num;

	num = 0;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > 2147483647)
			return (0);
		if (sign == -1 && - num < -2147483648)
			return (0);
		i++;
	}
	return (i);
}

int	is_valid_number(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	i = check_number(str, i, sign);
	if (i == 0)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	process_arg(char *arg, int *count)
{
	char	**split;
	int		j;

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
		(*count)++;
		j++;
	}
	ft_free_split(split);
	return (0);
}

int count_numbers(char **argv)
{
    int count = 0;
    int i = 1;

    while (argv[i])
    {

        if (process_arg(argv[i], &count) == -1)
            return (-1);
        i++;
    }
    return count;
}
