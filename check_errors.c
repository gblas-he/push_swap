/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:18:47 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/10 13:36:12 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_str(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_plus_or_min(str[i]) || ft_isdigit(str[i]) || str[i] == ' ')
		{
			if (is_plus_or_min(str[i]) && !ft_isdigit(str[i + 1]))
				free_all(data, NULL, 1);
			else
				i++;
		}
		else
			free_all(data, NULL, 1);
	}
}

void	check_args(char **av, int ac, t_data *data)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		check_str(av[i], data);
		i++;
	}
}

void	check_repeated(t_node **lst, t_data *data)
{
	t_node	*i_node;
	t_node	*j_node;

	i_node = *lst;
	while (i_node != NULL)
	{
		j_node = i_node->next;
		while (j_node != NULL)
		{
			if (j_node->value == i_node->value)
				free_all(data, *lst, 1);
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
}
