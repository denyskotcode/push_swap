/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkot <dkot@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:54:10 by dkot              #+#    #+#             */
/*   Updated: 2025/03/09 17:55:38 by dkot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_argument(char *arg, long long *numbers, int *index)
{
	char **split = ft_split(arg, ' ');
	if (!split)
		return -1;
	int j = 0;
	while (split[j])
	{
		numbers[(*index)++] = ft_atoi(split[j]);
		j++;
	}
	ft_free_split(split);
	return 0;
}

long long *parse_numbers(char **argv, int argc, int *total_count)
{
	*total_count = count_numbers(argv);
	if (*total_count == -1)
		return NULL;
	long long *numbers = malloc(sizeof(long long) * (*total_count));
	if (!numbers)
		return NULL;
	int index = 0;
	int i = 1;
	while (i < argc)
	{
		if (parse_argument(argv[i], numbers, &index) == -1)
		{
			free(numbers);
			return NULL;
		}
		i++;
	}
	return numbers;
}


int has_duplicates(long long *numbers, int total_count)
{
	int j = 0;
	while (j < total_count)
	{
		int k = j + 1;
		while (k < total_count)
		{
			if (numbers[j] == numbers[k])
				return -1;
			k++;
		}
		j++;
	}
	return 0;
}

int	check_duplicates(char **argv, int argc)
{
	int total_count;
	long long *numbers = parse_numbers(argv, argc, &total_count);
	if (!numbers)
		return -1;
	int result = has_duplicates(numbers, total_count);
	free(numbers);
	return result;
}
