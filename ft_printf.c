#include "ft_printf.h"
#include "libft/libft.h"

void			print_lst(t_printf_arg **head)
{
	t_printf_arg *tmp;
	// int i;

	tmp = *head;
	// i = 0;
	// int count = 0;

// cspdiuxX%

	printf("\n---------------PRINT_LST BEGIN---------------\n");
	while (tmp != NULL)
	{
		printf("printing list\n");
		printf("info on tmp:\narg: '%c'\nconversion: %d\nfield width: %zu\npadding: %d\nprecision: %d\nnext: %p\n\n", tmp->arg.c, tmp->conv, tmp->field_width, tmp->pad_type, tmp->precision, tmp->next);
		if (tmp->conv == c)
		{
			// printf("conversion isnt c???\n");

			// printf("true???\n");
			printf("conv: c\n");
			printf("addr: %p\nitem: %c\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.c, tmp->field_width, tmp->pad_type);
		}
		else if (tmp->conv == s)
		{
			// printf("true???\n");
			printf("addr: %p\nitem: %s\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.s, tmp->field_width, tmp->pad_type);
		}
		else if (tmp->conv == s)
		{
			// printf("true???\n");
			printf("addr: %p\nitem: %p\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.p, tmp->field_width, tmp->pad_type);
		}
		else if (tmp->conv == d)
		{
			printf("addr: %p\nitem: %lld\nfield width %zu\npad type: %u\nprecision: %zu\n\n", tmp, tmp->arg.i, tmp->field_width, tmp->pad_type, tmp->precision);


			// printf("d: %p\n%d\nflag string: %s\n\n", tmp, tmp->arg.d, tmp->format_str);
		}
		else if (tmp->conv == i)
		{
			// printf("true???\n");
			printf("addr: %p\nitem: %llu\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.i, tmp->field_width, tmp->pad_type);
		}
		else if (tmp->conv == u)
		{
			// printf("true???\n");
			printf("addr: %p\nitem: %llu\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.u, tmp->field_width, tmp->pad_type);
		}
		else if (tmp->conv == x)
		{
			// printf("true???\n");
			printf("addr: %p\nitem: %llx\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.u, tmp->field_width, tmp->pad_type);
		}
		else if (tmp->conv == X)
		{
			// printf("true???\n");
			printf("addr: %p\nitem: %llX\nfield width %zu\npad type: %u\n\n", tmp, tmp->arg.u, tmp->field_width, tmp->pad_type);
		}
		// else if (tmp->conv == i)
		// {
		// 	printf("i: %p\n%i\nflag string: %s\n\n", tmp, tmp->arg.i, tmp->format_str);
		// }
		// else if (tmp->conv == u)
		// {
		// 	printf("u: %p\n%u\nflag string: %s\n\n", tmp, tmp->arg.i, tmp->format_str);
		// }
		// else if (tmp->conv == s)
		// {
		// 	printf("s: %p\n%s\nflag string: %s\n\n", tmp, tmp->arg.s, tmp->format_str);
		// }
		// else if (tmp->conv == X)
		// {
		// 	printf("X: %p\n%X\nflag string: %s\n\n", tmp, tmp->arg.X, tmp->format_str);
		// }
		// else if (tmp->conv == x)
		// {
		// 	printf("x: %p\n%x\nflag string: %s\n\n", tmp, tmp->arg.x, tmp->format_str);
		// }
		// else if (tmp->conv == p)
		// {
		// 	printf("p: %p\n%p\nflag string: %s\n\n", tmp, tmp->arg.p, tmp->format_str);

			// PRINT POINTER
			// long c = tmp->arg.p;
			// char hex[13];
			// i = 11;
			// while(i >= 0)
			// {
			// 	hex[i] = c % 16;
			// 	if (hex[i] >= 10 && hex[i] <= 16)
			// 	{
			// 		hex[i] += 'a' - 10;
			// 	}
			// 	else if (hex[i] >= 0 && hex[i] <= 9)
			// 		hex[i] += '0';
			// 	c /= 16;
			// 	i--;
			// }
			// hex[12] = '\0';
			// write(1, "p: 0x", 5);
			// write(1, hex, 12);
			// write(1, "\n", 1);
		// }
		// else if (tmp-)
		tmp = tmp->next;
	}
	printf("----------------PRINT_LST END----------------\n\n");
}


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
	// printf("\n%p\n", head);
	va_end(ap);
	// print_lst(&head);
	ret = manage_print(str, &head);
	clear_list(&head);
	return (ret);
}