# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsaariko <jsaariko@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/03 20:38:39 by jsaariko       #+#    #+#                 #
#    Updated: 2020/03/06 17:53:42 by jsaariko      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = libft/
C_FILES	=	ft_printf.c \
			gen_arg_str.c \
			store_conv.c \
			gen_arg_list.c \
			parse.c \
			transition_code.c \
			base_state.c \
			dash_state.c \
			zero_state.c \
			num_state.c \
			ast_state.c \
			precision_state.c \
			error_state.c \
			print_result.c \
			execute.c \
			convert_char.c \
			convert_int.c \
			convert_hex.c \
			convert_str.c \
			convert_ptr.c \
			convert_float.c \
			format_buffer.c \
			clear_list.c

LIBFT_C = $(LIBFT_DIR)ft_putchar_fd \
				$(LIBFT_DIR)ft_putstr_fd \
				$(LIBFT_DIR)ft_putendl_fd \
				$(LIBFT_DIR)ft_putnbr_fd \
				$(LIBFT_DIR)ft_isalpha \
				$(LIBFT_DIR)ft_isdigit \
				$(LIBFT_DIR)ft_isalnum \
				$(LIBFT_DIR)ft_isascii \
				$(LIBFT_DIR)ft_isprint \
				$(LIBFT_DIR)ft_toupper \
				$(LIBFT_DIR)ft_tolower \
				$(LIBFT_DIR)ft_strlen \
				$(LIBFT_DIR)ft_memset \
				$(LIBFT_DIR)ft_bzero \
				$(LIBFT_DIR)ft_memcpy \
				$(LIBFT_DIR)ft_memccpy \
				$(LIBFT_DIR)ft_memmove \
				$(LIBFT_DIR)ft_memchr \
				$(LIBFT_DIR)ft_memcmp \
				$(LIBFT_DIR)ft_strlcpy \
				$(LIBFT_DIR)ft_strlcat \
				$(LIBFT_DIR)ft_strchr \
				$(LIBFT_DIR)ft_strrchr \
				$(LIBFT_DIR)ft_strnstr \
				$(LIBFT_DIR)ft_strncmp \
				$(LIBFT_DIR)ft_atoi \
				$(LIBFT_DIR)ft_calloc \
				$(LIBFT_DIR)ft_substr \
				$(LIBFT_DIR)ft_strjoin \
				$(LIBFT_DIR)ft_strtrim \
				$(LIBFT_DIR)ft_strmapi \
				$(LIBFT_DIR)ft_itoa \
				$(LIBFT_DIR)ft_split \
				$(LIBFT_DIR)ft_strdup \
				$(LIBFT_DIR)ft_numlen \
				$(LIBFT_DIR)ft_realloc \
				$(LIBFT_DIR)ft_recalloc \
				$(LIBFT_DIR)ft_strchrset \
				$(LIBFT_DIR)ft_strdupchr \
				$(LIBFT_DIR)ft_strjoinchar \
				$(LIBFT_DIR)ft_numlen_base \
				$(LIBFT_DIR)ft_numtochar_base \
				$(LIBFT_DIR)ft_lltoa_base \
				$(LIBFT_DIR)ft_ulltoa_base \
				$(LIBFT_DIR)ft_toupperstr \
				$(LIBFT_DIR)ft_tolowerstr \
				$(LIBFT_DIR)ft_strjoinindex \
				$(LIBFT_DIR)ft_strmatch

LIBFT_FILES = $(LIBFT_C:%=%.o)
O_FILES	=	$(C_FILES:%.c=%.o)
FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

#remember to compile with flags

$(NAME): lib $(O_FILES)
	@ar -rc $(NAME) $(LIBFT_FILES) $(O_FILES)
	@ranlib $(NAME)
	@echo "libftprintf.a compiled"

$(O_FILES):
	@gcc $(FLAGS) -c $(C_FILES)
	@echo "Printf object files compiled"

lib:
	@make -C $(LIBFT_DIR) objects

test: fclean $(NAME)
	@gcc -o test testmain.c libftprintf.a
	@echo "Created test executable"

clean:
	@rm -f $(O_FILES)
	@make -C $(LIBFT_DIR) clean
	@echo "Cleared printf object files"

clean_test:
	@rm -f test
	@rm -f lindsay_tests
	@echo "Cleared test executables on printf"

fclean: clean clean_test
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Printf all clean!"

lindsay: $(NAME)
	gcc -o lindsay_tests libftprintf.a ../limartin_tests/main.c

re: fclean all

	