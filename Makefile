# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 20:38:39 by jsaariko       #+#    #+#                 #
#    Updated: 2019/12/05 22:11:51 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all: test main

main:
	gcc -o ft main.c ft_itoa_base.c ft_numlen_base.c -Llibft -lft

test:
	gcc -o real test.c