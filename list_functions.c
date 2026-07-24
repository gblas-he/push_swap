/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 11:04:11 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/09 15:42:37 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = num;
	node->idx = 0;
	node->next = NULL;
	return (node);
}

void	lst_addback(t_node **lst, t_node *new_node)
{
	t_node	*last;

	if (!lst)
		print_err();
	if (new_node == NULL)
	{
		free_lst(lst);
		print_err();
	}
	last = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	if (lst && new_node)
	{
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
}

int	lst_size(t_node *lst)
{
	int		count;
	t_node	*current_node;

	current_node = lst;
	count = 0;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		count++;
	}
	return (count);
}
