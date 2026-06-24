/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:27:48 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/28 16:27:50 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	parse_args(t_data **data, int ac, char **av)
{
	void	*nums;
	int		flags_count;
	size_t	len;

	len = 0;
	flags_count = count_flags(ac, av);
	*data = malloc(sizeof(t_data));
	if (*data == NULL)
		return ;
	if (flags_count)
		parse_flags(flags_count, av, *data);
	else
		(*data)->strategy = "adaptive";
	nums = fill_nums_arr(ac - 1 - flags_count, flags_count, av, &len);
	if (nums == NULL)
	{
		free(*data);
		*data = NULL;
		return ;
	}
	if (ac - flags_count == 2)
		fill_alg_data(data, nums, 0, len);
	else
		fill_alg_data(data, nums, 1, len);
}

void	*fill_nums_arr(int ac, int flags, char **av, size_t *len)
{
	char	**arr;
	int		*nums_arr;

	if (ac == 1)
	{
		check_str(*(av + 1 + flags));
		arr = ft_split(*(av + 1 + flags), ' ', len);
		if (arr == NULL || *len == 1)
		{
			free_str_arr(arr, *len);
			return (NULL);
		}
		return (arr);
	}
	else
	{
		check_args(&av[flags + 1], ac);
		nums_arr = nums_array(&av[flags + 1], ac);
		*len = ac;
		if (nums_arr == NULL)
			return (NULL);
		return (nums_arr);
	}
	return (NULL);
}

int	*nums_array(char **av, int ac)
{
	int	*arr;
	int	i;

	arr = malloc(ac * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i] = ft_atoi(av[i]);
		i++;
	}
	return (arr);
}
