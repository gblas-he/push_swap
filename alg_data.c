/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:40:25 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/16 13:40:27 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->arr = 0;
	data->arr_type = 0;
	data->bench = 0;
	data->bm = init_bench();
	data->disorder = 0;
	data->size = 0;
	data->s_flag = 0;
	data->strategy = 0;
	return (data);
}

t_node	*init_stack(t_data *data, void *nums)
{
	t_node	*lst;

	lst = NULL;
	if (data->size == 1)
	{
		free_str_arr((char **)nums, data->size);
		return (NULL);
	}
	if (data->arr_type == CHAR)
	{
		fill_from_string_array(&lst, nums);
		free_str_arr((char **)nums, data->size);
	}
	else
	{
		fill_from_int_array(&lst, data, nums);
		free((int *)nums);
	}
	return (lst);
}

void	fill_from_string_array(t_node **lst, void *nums)
{
	int	i;

	i = 0;
	while (((char **)nums)[i] != 0)
	{
		if (!*lst)
			*lst = lst_new(ft_atoi(((char **)nums)[i]));
		else
			lst_addback(lst, lst_new(ft_atoi(((char **)nums)[i])));
		i++;
	}
}

void	fill_from_int_array(t_node **lst, t_data *data, void *nums)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{
		if (!*lst)
			*lst = lst_new(((int *)nums)[i]);
		else
			lst_addback(lst, lst_new(((int *)nums)[i]));
		i++;
	}
}
