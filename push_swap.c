/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:04 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/16 17:02:37 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_node **a, t_data *data)
{
	int		size;

	size = lst_size(*a);
	if (size <= 10)
		simple_alg(a, data);
	else if (size > 10 && size <= 100)
		medium_alg(a, data);
	else
	{
		if (data->disorder < 0.2)
			simple_alg(a, data);
		else if (data->disorder >= 0.2 && data->disorder < 0.5)
			medium_alg(a, data);
		else
			complex_alg(a, data);
	}
}

int	isordered(t_node **stack_a)
{
	t_node	*ptr1;

	ptr1 = *stack_a;
	while (ptr1->next != NULL)
	{
		if (ptr1->value < ptr1->next->value)
			ptr1 = ptr1->next;
		else
			return (0);
	}
	return (1);
}

void	push_swap(t_node **stack_a, t_data *data)
{
	check_repeated(stack_a, data);
	index_list(stack_a);
	data->disorder = compute_disorder(stack_a);
	if (isordered(stack_a))
	{
		if (data->bench)
			print_bench(data);
		free_lst(stack_a);
		return ;
	}
	if (!ft_strncmp(data->strategy, "simple", 6))
		simple_alg(stack_a, data);
	else if (!ft_strncmp(data->strategy, "medium", 6))
		medium_alg(stack_a, data);
	else if (!ft_strncmp(data->strategy, "complex", 7))
		complex_alg(stack_a, data);
	else if (!ft_strncmp(data->strategy, "adaptive", 8))
		adaptive(stack_a, data);
	if (data->bench)
		print_bench(data);
}

int	main(int ac, char *av[])
{
	t_data	*data;
	t_node	*stack_a;
	void	*nums;

	data = init_data();
	if (data == NULL)
		return (0);
	stack_a = NULL;
	if (ac != 1)
	{
		av = parse_flags(av + 1, data);
		if (data == NULL || data->strategy == NULL)
			return (0);
		nums = parse_args(av, data);
		if (nums)
		{
			stack_a = init_stack(data, nums);
			if (stack_a)
				push_swap(&stack_a, data);
		}
		free_all(data, stack_a, 0);
	}
	return (0);
}
