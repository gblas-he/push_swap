/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:52:39 by jdiaz-ec          #+#    #+#             */
/*   Updated: 2026/03/19 12:07:49 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

// Array Type Enum 
enum e_arrtype
{
	CHAR,
	INT
};

// Operations count
typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_ops;
}	t_bench;

// algorithm and stack data
typedef struct s_algdata
{
	t_bench			*bm;
	void			*arr;
	char			*strategy;
	size_t			size;
	double			disorder;
	int				bench;
	enum e_arrtype	arr_type;
}	t_data;

// Stack nodes
typedef struct s_node
{
	struct s_node	*next;
	int				value;
	int				idx;
}	t_node;

char		*select_strategy(char *s);
void		parse_flags(int f_count, char **av, int *bench, char **strategy);
int			count_flags(int ac, char **av);
void		check_flag(int *flag, int *f_count);
void		parse_args(t_data **data, int ac, char **av);
t_data		*fill_alg_data(void *nums_array, enum e_arrtype type, int len);
void		*fill_nums_arr(int ac, int flags, char **av, size_t *len);
int			*nums_array(char **av, int ac);
void		fill_stack_from_arr(t_node **lst, t_data *data);
void		fill_from_string_array(t_node **lst, t_data *data);
void		fill_from_int_array(t_node **lst, t_data *data);
t_bench		*init_bench(void);
void		print_bench(t_data *data);
char		*compute_complexity(t_data *data);
void		ft_printf(const char *format, ...);
void		convert(va_list args, char specifier);
void		ft_printchar(char c);
void		ft_printstr(char *s);
void		ft_printint(int n);
void		ft_printdouble(double n);
int			fill_arr(char **arr, char *str, char c);
int			count_args(char *s);
int			safe_malloc(char **arr, int pos, size_t len);
char		**ft_split(char *str, char c, size_t *len);
void		print_err(void);
void		check_args(char **av, int ac);
void		check_str(char *str);
void		check_repeated(t_node **lst, t_data *data);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
int			is_plus_or_min(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_atoi(char *s);
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr(char *s, int fd);
char		*ft_itoa(int n);
char		*ft_ftoa(double d);
size_t		ft_strlen(char *s);
int			count_digits(long n);
char		*ft_malloc(int n);
void		fill_from_double(char *str, int digits, int int_part, int rem_part);
int			fill_int_part(char *str, int int_part, int digits);
int			fill_rem_part(char *str, int rem_part, int digits);
char		*ft_strdup(char *str);
void		lst_addback(t_node **lst, t_node *new_node);
t_node		*lst_new(int num);
int			lst_size(t_node *lst);
void		free_str_arr(char **arr, size_t len);
void		free_lst(t_node **lst);
void		push_swap(t_node **stack_a, t_data *data);
int			isordered(t_node **stack_a);
void		swap(t_node **lst);
void		sa(t_node **a, t_data *data);
void		sb(t_node **b, t_data *data);
void		ss(t_node **a, t_node **b, t_data *data);
void		push(t_node **dest, t_node **src);
void		pa(t_node **a, t_node **b, t_data *data);
void		pb(t_node **a, t_node **b, t_data *data);
void		rotate(t_node **lst);
void		ra(t_node **a, t_data *data);
void		rb(t_node **b, t_data *data);
void		rr(t_node **a, t_node **b, t_data *data);
void		rev_rotate(t_node **lst);
void		rra(t_node **a, t_data *data);
void		rrb(t_node **b, t_data *data);
void		rrr(t_node **a, t_node **b, t_data *data);
double		compute_disorder(t_node **stack);
void		q_swap(int *a, int *b);
void		quicksort(int *arr, int left, int right);
void		apply_index(t_node *a, int *arr, int size);
void		index_list(t_node **a);
void		simple_alg(t_node **a, t_data *data);
void		medium_alg(t_node **stack_a, t_data *data);
void		complex_alg(t_node **stack_a, t_data *data);
void		chunks_sort(t_node **a, t_node **b, t_data *data);
void		selection_sort(t_node **a, t_node **b, t_data *data);
void		radix_sort(t_node **a, t_node **b, t_data *data);
int			find_max_pos(t_node *b);
void		push_chunks(t_node **a, t_node **b, int chunks_size, t_data *data);
void		push_back(t_node **a, t_node **b, t_data *data);
void		adaptive(t_node **a, t_data *data);
void		sort_three(t_node **a, t_data *data);
int			get_max_bits(t_node *a);

#endif