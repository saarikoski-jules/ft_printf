# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 20:38:39 by jsaariko       #+#    #+#                 #
#    Updated: 2020/02/16 20:38:17 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# NAME = libftprintf.a
# C_FILES	=	ft_printf.c \
# 			parse.c \
# 			transition_code.c \
# 			base_state.c \
# 			dash_state.c \
# 			zero_state.c \
# 			num_state.c \
# 			precision_state.c \
# 			error_state.c \

# O_FILES	=	$(C_FILES:%.c=%.o)
# FLAGS	=	-Wall -Wextra -Werror
# LIBFT 	=	-Ilibft -Llibft -lft


# all: $(NAME)

# $(NAME): $(O_FILES)
# 	@ar -rc $(NAME) $(O_FILES) libft/libft.a
# 	@ranlib $(NAME)
# 	@echo "libftprintf.a compiled"

# $(O_FILES):
# 	@gcc $(FLAGS) -c $(C_FILES)

# test: $(NAME)
# 	@gcc -o test testmain.c -L. -lftprintf
# 	@echo "Created test executable"

# clean:
# 	@rm -f $(O_FILES)
# 	@echo "clean"

# fclean: clean
# 	@rm $(NAME)

all: main test



main:
	gcc -o ft testmain.c ft_printf.c parse.c base_state.c num_state.c error_state.c dash_state.c zero_state.c precision_state.c transition_code.c print_result.c execute.c convert_char.c convert_int.c convert_hex.c convert_str.c convert_ptr.c clear_list.c gen_arg_str.c format_buffer.c -Ilibft -Llibft -lft

test:
	gcc -o real test.c ft_itoa_base.c ft_numlen_base.c -Ilibft -Llibft -lft