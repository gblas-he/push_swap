/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 17:37:40 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/17 16:46:53 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	parse_flags(int f_count, char **av, t_data *data)
{
	int	i;
	int	s_flag;

	s_flag = 0;
	i = 1;
	while (f_count > 0)
	{
		if (f_count > 0 && !ft_strncmp("--bench", av[i], 7))
		{
			check_flag(&data->bench, &f_count, &data);
			i++;
			if (!f_count && !s_flag)
				data->strategy = "adaptive";
		}
		if (f_count > 0 && !ft_strncmp("--", av[i], 2))
		{
			check_flag(&s_flag, &f_count, &data);
			data->strategy = select_strategy(av[i], data);
			i++;
		}
	}
}

char	*select_strategy(char *s, t_data *data)
{
	int	i;

	i = 2;
	if (!ft_strncmp(s + i, "simple", 7))
		return (s + 2);
	else if (!ft_strncmp(s + i, "medium", 7))
		return (s + 2);
	else if (!ft_strncmp(s + i, "complex", 8))
		return (s + 2);
	else if (!ft_strncmp(s + i, "adaptive", 9))
		return (s + 2);
	else
	{
		free(data);
		print_err();
	}
	return (NULL);
}

int	count_flags(int ac, char **av)
{
	int	i;
	int	flags;

	i = 1;
	flags = 0;
	if (!av[2])
		print_err();
	while (i < ac - 1)
	{
		if (av[i][0] == '-' && ft_isdigit(av[i][1]))
			break ;
		else if (av[i][0] == '-' && ft_isalpha(av[i][1]))
			print_err();
		else if (av[i][0] == '-' && av[i][1] == '-')
			flags++;
		else if (av[i][0] == '-' && av[i][1] == '\0')
			print_err();
		i++;
	}
	return (flags);
}

void	check_flag(int *flag, int *f_count, t_data **data)
{
	if (*flag)
	{
		free(*data);
		print_err();
	}
	else
	{
		*flag = 1;
		*f_count -= 1;
	}
}
