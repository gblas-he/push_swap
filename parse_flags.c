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

char	**parse_flags(char **av, t_data *data)
{
	int	flags_count;
	int	i;

	flags_count = count_flags(av, data);
	i = 0;
	if (!flags_count)
		data->strategy = select_strategy("--adaptive", data);
	while (flags_count > 0)
	{
		if (flags_count > 0 && !ft_strncmp("--bench", av[i], 7))
		{
			check_flag(&flags_count, &data, BENCH);
			i++;
			if (!flags_count && !data->s_flag)
				data->strategy = select_strategy("--adaptive", data);
		}
		if (flags_count > 0 && !ft_strncmp("--", av[i], 2))
		{
			check_flag(&flags_count, &data, STRATEGY);
			data->strategy = select_strategy(av[i], data);
			i++;
		}
	}
	return (av + i);
}

char	*select_strategy(char *s, t_data *data)
{
	s += 2;
	if (!ft_strncmp(s, "simple", 9))
		data->strategy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else if (!ft_strncmp(s, "medium", 9))
		data->strategy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else if (!ft_strncmp(s, "complex", 10))
		data->strategy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else if (!ft_strncmp(s, "adaptive", 11))
		data->strategy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		free_all(data, NULL, 1);
	if (data->strategy == NULL)
		return (NULL);
	ft_strlcpy(data->strategy, s, ft_strlen(s) + 1);
	return (data->strategy);
}

int	count_flags(char **av, t_data *data)
{
	int	i;
	int	flags;

	i = 0;
	flags = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i][0]))
			break ;
		if (av[i][0] == '-' && ft_isdigit(av[i][1]))
			break ;
		else if (av[i][0] == '-' && ft_isalpha(av[i][1]))
			free_all(data, NULL, 1);
		else if (ft_isalpha(av[i][0]))
			free_all(data, NULL, 1);
		else if (av[i][0] == '-' && av[i][1] == '-')
			flags++;
		else if (av[i][0] == '-' && av[i][1] == '\0')
			free_all(data, NULL, 1);
		i++;
	}
	return (flags);
}

void	check_flag(int *f_count, t_data **data, enum e_flag flag)
{
	if (flag == BENCH)
	{
		if ((*data)->bench)
			free_all(*data, NULL, 1);
		else
		{
			(*data)->bench = 1;
			*f_count -= 1;
		}
	}
	else
	{
		if ((*data)->s_flag)
			free_all(*data, NULL, 1);
		else
		{
			(*data)->s_flag = 1;
			*f_count -= 1;
		}
	}
}
