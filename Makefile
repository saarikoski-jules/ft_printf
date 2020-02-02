# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 20:38:39 by jsaariko       #+#    #+#                 #
#    Updated: 2020/02/02 20:14:03 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all: main test

main:
	gcc -o ft main.c ft_itoa_base.c ft_numlen_base.c parse.c -Llibft -lft

test:
	gcc -o real test.c ft_itoa_base.c ft_numlen_base.c -Llibft -lft