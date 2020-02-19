#include "ft_printf.h"
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{

	t_printf_arg	*head;
	va_list			ap;
	int				ret;

	head = NULL;
	va_start(ap, str);
	if (gen_arg_list(&head, str, ap) == -1)
	{
		clear_list(&head);
		return (-1);
	}
	va_end(ap);
	ret = manage_print(str, &head);
	clear_list(&head);
	return (ret);
}