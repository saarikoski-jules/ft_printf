//Honest to god I dont even know where to start

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h> //REMOVE
#include <unistd.h>
#include "libft/libft.h"

t_printf_arg	*gen_elem(t_printf_arg **head)
{
	t_printf_arg	*cur;
	t_printf_arg	*new;

	cur = *head;
	new = malloc(sizeof(t_printf_arg));
	new->next = NULL;
	new->arg = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}	
	return(new);
}

void	gen_arg_list(t_printf_arg **head, const char *str, va_list ap)
{
	int				i;
	t_printf_arg	*cur;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			cur = gen_elem(head);
			cur->arg = va_arg(ap, void*);
			i++;
		}
		i++;
	}
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
	printf("%c\n", (int)head->next->arg);
	while (str[i] == '\0')
	{
		
	}	


	// printf("count: %d\n", count);
	// printf("%d\n", va_arg(ap, int));
	// printf("%s\n", va_arg(ap, char*));

	va_end(ap);
	return (0);
}

int main()
{
	ft_printf("str %c %c", 'c', 'd');
	return (0);
}