# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 20:38:39 by jsaariko       #+#    #+#                 #
#    Updated: 2020/02/10 16:40:23 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all: main test

main:
	gcc -Wall -Wextra -Werror -o ft main.c ft_itoa_base.c ft_numlen_base.c parse.c base_state.c num_state.c error_state.c dash_state.c zero_state.c precision_state.c transition_code.c -Llibft -lft

test:
	gcc -o real test.c ft_itoa_base.c ft_numlen_base.c -Llibft -lft