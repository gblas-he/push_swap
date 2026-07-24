/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:03:29 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/27 11:03:39 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str_arr(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_lst(t_node **lst)
{
	t_node	*node;
	t_node	*next;

	node = *lst;
	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*lst = NULL;
}

void	free_all(t_data *data, t_node *stack, int x)
{
	if (data != NULL)
	{
		free(data->strategy);
		free(data->bm);
		free(data);
	}
	if (stack != NULL)
		free_lst(&stack);
	if (x)
		print_err();
}
