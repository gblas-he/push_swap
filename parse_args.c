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

void	parse_args(t_data **data, int ac, char **av)
{
	void	*nums;
	int		flags_count;
	int		bench;
	size_t	len;
	char	*strategy;

	bench = 0;
	len = 0;
	flags_count = count_flags(ac, av);
	if (!flags_count)
		strategy = "adaptive";
	else
		parse_flags(flags_count, av, &bench, &strategy);
	nums = fill_nums_arr(ac - 1 - flags_count, flags_count, av, &len);
	if (nums == NULL)
		return ;
	if (ac - flags_count == 2)
		*data = fill_alg_data(nums, 0, len);
	else
		*data = fill_alg_data(nums, 1, len);
	if (*data == NULL)
		print_err();
	(*data)->bench = bench;
	(*data)->strategy = strategy;
	(*data)->bm = init_bench();
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
