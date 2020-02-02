
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h> //REMOVE
#include <unistd.h>
#include "libft/libft.h"

void			print_lst(t_printf_arg **head)
{
	t_printf_arg *tmp;
	int i;

	tmp = *head;
	i = 0;
	int count = 0;
	printf("\n---------------PRINT_LST BEGIN---------------\n");
	while (tmp != NULL)
	{
		if (tmp->conv == c)
		{
			printf("c: %p\n%c\nflag string: %s\n\n", tmp, tmp->arg.c, tmp->format_str);
		}
		else if (tmp->conv == d)
		{
			printf("d: %p\n%d\nflag string: %s\n\n", tmp, tmp->arg.d, tmp->format_str);
		}
		else if (tmp->conv == i)
		{
			printf("i: %p\n%i\nflag string: %s\n\n", tmp, tmp->arg.i, tmp->format_str);
		}
		else if (tmp->conv == u)
		{
			printf("u: %p\n%u\nflag string: %s\n\n", tmp, tmp->arg.i, tmp->format_str);
		}
		else if (tmp->conv == s)
		{
			printf("s: %p\n%s\nflag string: %s\n\n", tmp, tmp->arg.s, tmp->format_str);
		}
		else if (tmp->conv == X)
		{
			printf("X: %p\n%X\nflag string: %s\n\n", tmp, tmp->arg.X, tmp->format_str);
		}
		else if (tmp->conv == x)
		{
			printf("x: %p\n%x\nflag string: %s\n\n", tmp, tmp->arg.x, tmp->format_str);
		}
		else if (tmp->conv == p)
		{
			printf("p: %p\n%p\nflag string: %s\n\n", tmp, tmp->arg.p, tmp->format_str);

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
		}
		// else if (tmp-)
		tmp = tmp->next;
	}
	printf("----------------PRINT_LST END----------------\n\n");
}

t_printf_arg	*gen_elem(t_printf_arg **head)
{
	t_printf_arg	*cur;
	t_printf_arg	*new;

	new = malloc(sizeof(t_printf_arg));
	if (!new)
		return (NULL);
	printf("New item: %p\n", new);
	new->next = NULL;
	// new->arg.c = '0';
	if (*head == NULL)
	{
		*head = new;
		// printf("in if statement: new: %p, *head %p\n", new, *head);
	}
	else
	{
		// printf("head aint NULL\n");
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	// printf("end: new: %p, *head %p\n", new, *head);

	// print_lst(head);

	// printf("new: %p, %d\n", new, new->arg.c);
	// if (cur != NULL)
	// 	printf("cur: %p	 %d\n", cur, cur->arg.c);
	// else
	// 	printf("cur: NULL\n");
	// if (*head != NULL)
	// 	printf("head: %p, %d\n", *head, (*head)->arg.c);
	// else
	// 	printf("head: NULL\n");
	return(new);
}

void	gen_arg_list(t_printf_arg **head, const char *str, va_list ap)
{
	int				i;
	t_printf_arg	*cur;
	char			item;
	char			*convs = "cspdiuxX%";

	i = 0;
	while(str[i] != '\0')
	{

		// printf("'%c'\n", str[i]);
		if (str[i] == '%')
		{
			cur = gen_elem(head);
			cur->format_str = ft_strdupchr(str + i + 1, convs); //Instead of this, directly parse the information into a usable format in the struct.
			// AKA pass the string and current arg to the parser.
			manage_parser(&cur, cur->format_str);
			i += ft_strchrset(str + i + 1, convs);
			if (str[i + 1] == 'c')
			{
				// cur = gen_elem(head);
				cur->arg.c = va_arg(ap, unsigned int);
				cur->conv = c;
			}
			else if (str[i + 1] == 'd')
			{
				// cur = gen_elem(head);
				// printf("%p\n", cur);
				cur->arg.d = va_arg(ap, int);
				cur->conv = d;
			}
			else if (str[i + 1] == 'i')
			{
				// cur = gen_elem(head);
				cur->arg.i = va_arg(ap, int);
				cur->conv = i;
			}
			else if (str[i + 1] == 's')
			{
				// cur = gen_elem(head);
				cur->arg.s = ft_strdup(va_arg(ap, char *));
				cur->conv = s;
			}
			else if (str[i + 1] == 'X')
			{
				// cur = gen_elem(head);
				// cur->arg.X = ft_itoa_base(va_arg(ap, int), 16);
				cur->arg.X = va_arg(ap, unsigned int);
				cur->conv = X;
			}
			else if (str[i + 1] == 'x')
			{
				// cur = gen_elem(head);
				// cur->arg.X = ft_itoa_base(va_arg(ap, int), 16);
				cur->arg.x = va_arg(ap, unsigned int);
				cur->conv = x;
			}
			else if (str[i + 1] == 'p')
			{
				// cur = gen_elem(head);
				cur->arg.p = va_arg(ap, void *);
				cur->conv = p;
			}
			else if (str[i + 1] == 'u')
			{
				cur->arg.u = va_arg(ap, unsigned int);
				cur->conv = u;
			}
			else if (str[i + 1] == '%')
			{
				cur->arg.c = '%';
				cur->conv = c;
			}
			// cur = gen_elem(head);
			// cur->arg = va_arg(ap, void*);
			i++;
		}
		i++;
	}
	// print_lst(head);
}

int ft_printf(const char *str, ...)
{

	t_printf_arg	*head;
	t_printf_arg	*cur;
	va_list			ap;
	int				i;
	int				count;

	i = 0;
	count = 0;
	head = NULL;
	va_start(ap, str);

	// while(str[i] != '\0')
	// {
	// 	if (str[i] == '%')
	// 	{
	// 		cur = gen_elem(&head);
	// 		cur->arg = va_arg(ap, void*);
	// 		// printf("%c\n", (int)cur->arg);
	// 		i++;
	// 	}
	// 	i++;
	// }

	gen_arg_list(&head, str, ap);
	// printf("done gen lst\n");
	// printf("why");
	// printf("end: %c\n", head->arg.c);
	// printf("end: %c\n", head->next->arg.c);
	// printf("end: %c\n", head->next->next->arg.d);
	// while (str[i] == '\0')
	// {
	// }	


	// printf("count: %d\n", count);
	// printf("%d\n", va_arg(ap, int));
	// printf("%s\n", va_arg(ap, char*));

	va_end(ap);
	print_lst(&head);
	return (0);
}

int main()
{
	char c;
	int i = -12;

	ft_printf("str %aaaaac, %000-s, %c, %c, %d, %d, %X, %p, %x %u %%", 'c', "I'm a string", '9', '2', 7, 12, 12, &c, 12, i);
	// printf("why");
	return (0);
}