//Honest to god I dont even know where to start

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h> //REMOVE
#include <unistd.h>
#include "libft/libft.h"

void			print_lst(t_printf_arg **head, const char *str)
{
	t_printf_arg *tmp;
	int i;

	tmp = *head;
	i = 0;
	printf("---------------PRINT_LST BEGIN---------------\n");
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				printf("%p, %c\n", tmp, tmp->arg.c);
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				printf("%p, %d\n", tmp, tmp->arg.d);
			else if (str[i + 1] == 's')
				printf("%p, %s\n", tmp, tmp->arg.s);
			tmp = tmp->next;
			i++;
		}
		i++;
	}
	printf("----------------PRINT_LST END----------------\n\n");
}

t_printf_arg	*gen_elem(t_printf_arg **head)
{
	t_printf_arg	*cur;
	t_printf_arg	*new;

	new = malloc(sizeof(t_printf_arg));
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

	i = 0;
	while(str[i] != '\0')
	{

		// printf("'%c'\n", str[i]);
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
			{
				cur = gen_elem(head);
				cur->arg.c = va_arg(ap, int);
				i++;
			}
			else if (str[i + 1] == 'd')
			{
				cur = gen_elem(head);
				// printf("%p\n", cur);
				cur->arg.d = va_arg(ap, int);
				i++;
			}
			else if (str[i + 1] == 'i')
			{
				cur = gen_elem(head);
				cur->arg.i = va_arg(ap, int);
				i++;
			}
			else if (str[i + 1] == 's')
			{
				cur = gen_elem(head);
				cur->arg.s = ft_strdup(va_arg(ap, char *));
				i++;
			}
			// cur = gen_elem(head);
			// cur->arg = va_arg(ap, void*);
			// i++;
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
	print_lst(&head, str);
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
	return (0);
}

int main()
{
	ft_printf("str %c, %s, %c, %c, %d", 'c', "I'm a string", '9', '2', 7);
	return (0);
}