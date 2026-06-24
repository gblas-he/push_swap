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

void	fill_alg_data(t_data **data, void *nums_array, enum e_arrtype type, int len)
{
	(*data)->arr_type = type;
	(*data)->arr = nums_array;
	(*data)->size = len;
	(*data)->disorder = 0;
	(*data)->bm = init_bench();
}

void	fill_stack_from_arr(t_node **lst, t_data *data)
{
	if (data->arr_type == 0)
	{
		fill_from_string_array(lst, data);
		free_str_arr((char **)data->arr, data->size);
	}
	else
	{
		fill_from_int_array(lst, data);
		free((int *)data->arr);
	}
}

void	fill_from_string_array(t_node **lst, t_data *data)
{
	int	i;

	i = 0;
	while (((char **)data->arr)[i] != 0)
	{
		if (!*lst)
			*lst = lst_new(ft_atoi(((char **)data->arr)[i]));
		else
			lst_addback(lst, lst_new(ft_atoi(((char **)data->arr)[i])));
		i++;
	}
}

void	fill_from_int_array(t_node **lst, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{
		if (!*lst)
			*lst = lst_new(((int *)data->arr)[i]);
		else
			lst_addback(lst, lst_new(((int *)data->arr)[i]));
		i++;
	}
}
