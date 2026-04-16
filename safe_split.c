/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:46:57 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/02/25 18:50:35 by jdiaz-ec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char *s)
{
	int	args;
	int	i;
	int	is_arg;

	args = 0;
	i = 0;
	while (s[i] != '\0')
	{
		is_arg = 0;
		while (s[i] == ' ' && s[i] != '\0')
			i++;
		while (s[i] != ' ' && s[i] != '\0')
		{
			if (!is_arg)
			{
				is_arg = 1;
				args++;
			}
			i++;
		}
	}
	return (args);
}

int	fill_arr(char **arr, char *str, char c)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		len = 0;
		while (str[i] == c && str[i] != '\0')
			++i;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			len++;
		}
		if (len)
		{
			if (safe_malloc(arr, j, len + 1))
				return (1);
			ft_strlcpy(arr[j], &str[i - len], len + 1);
			j++;
		}
	}
	return (0);
}

int	safe_malloc(char **arr, int pos, size_t len)
{
	int	i;

	i = 0;
	arr[pos] = malloc(len);
	if (arr[pos] == NULL)
	{
		while (i < pos)
			free(arr[i++]);
		free(arr);
		return (1);
	}
	return (0);
}

char	**ft_split(char *str, char c, size_t *words)
{
	char	**arr;

	*words = count_args(str);
	arr = malloc((*words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[*words] = 0;
	if (fill_arr(arr, str, c))
		return (NULL);
	return (arr);
}
