# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdiaz-ec <jdiaz-ec@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 14:39:24 by jdiaz-ec          #+#    #+#              #
#    Updated: 2026/03/18 14:39:26 by jdiaz-ec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = alg_data.c bench_utils.c check_errors.c chunks_sort.c \
	complex_alg.c free_functions.c ft_ftoa.c ft_itoa.c ft_printf.c \
	list_functions.c medium_alg.c parse_args.c parse_flags.c \
	print_letters.c print_nums.c push_ops.c push_swap.c rev_rotate_ops.c \
	rotate_ops.c safe_split.c selection_sort.c simple_alg.c swap_ops.c \
	utils_alg.c utils.c utils2.c

OBJS := $(SRC:%.c=%.o)

NAME = push_swap

CC = cc

CCFLAGS = -Wall -Wextra -Werror -g3

LIBFLAG = -I.

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(LIBFLAG) $(CCFLAGS) -o $@ -c $<

.PHONY: clean all fclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all