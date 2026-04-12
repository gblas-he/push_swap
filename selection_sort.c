/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:36:22 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/10 18:26:23 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Buscar el mínimo
t_node	*s_min_node(t_node *a, int *min_pos, int *size)
{
	t_node	*min;

	while (a)
	{
		min = a;
		*min_pos = 0;
		*size = 0;
		while (a)
		{
			if (a->value < min->value)
			{
				min = a;
				*min_pos = *size;
			}
			a = a->next;
			(*size)++;
		}
	}
	return (min);
}

void	selection_sort(t_node **a, t_node **b, t_data *data)
{
	t_node	*min;
	int		min_pos;
	int		size;

	while (*a && !isordered(a))
	{
		min = s_min_node(*a, &min_pos, &size);
		if (min_pos <= size / 2)
		{
			while ((*a)->value != min->value)
				ra(a, data);
		}
		else
		{
			while ((*a)->value != min->value)
				rra(a, data);
		}
		if (!isordered(a))
			pb(a, b, data);
		else
			break;
	}
	while (*b)
		pa(a, b, data);
}
