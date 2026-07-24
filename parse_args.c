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

void	*parse_args(char **av, t_data *data)
{
	void	*nums;
	int		args_count;

	args_count = count_args(av);
	nums = fill_nums_arr(args_count, av, data);
	if (args_count == 1)
		data->arr_type = CHAR;
	else
		data->arr_type = INT;
	return (nums);
}

int	count_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	*fill_nums_arr(int ac, char **av, t_data *data)
{
	char	**arr;
	int		*nums_arr;

	if (ac == 1)
	{
		check_str(*(av), data);
		arr = ft_split(*(av), ' ', &data->size);
		if (arr == NULL)
			return (NULL);
		return (arr);
	}
	else
	{
		check_args(&av[0], ac, data);
		nums_arr = nums_array(&av[0], ac);
		data->size = ac;
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
