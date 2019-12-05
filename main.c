//Honest to god I dont even know where to start

#include <stdarg.h>
#include <stdio.h> //REMOVE
#include <unistd.h>
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	int i;
	char c;
	int ret;
	char *val;

	i = 0;
	while(str[i] != '\0')
	{
		// printf("in while loop\n");
		if (str[i] == '%')
		{
			// printf("Entered if condition\n");
			c = str[i + 1];
			// printf("%c\n", c);
			break;
		}
		i++;
	}
	// printf("%c", c);
	va_start(ap, str);

	if (c == 'c')
	{
		// ret = va_arg(ap, int) + '0';
		// printf("%c\n", va_arg(ap, int));
		val = (char *)malloc(2 * sizeof(char));
		val[0] = va_arg(ap, int);
		val[1] = '\0';
		// ret = va_arg(ap, int);
		// printf("value of c = %s\n", val);
	}
	else if (c == 'd' || c == 'i')
	{
		val = ft_strdup(ft_itoa(va_arg(ap, int)));
		// printf("d");
		// printf("%s\n", va_arg(ap, char*));
		// val = ft_strdup(va_arg(ap, char*));
		// ret = ft_atoi(val);
	}
	else if (c == 's')
	{
		val = ft_strdup(va_arg(ap, char*));
	}

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			write(1, val, ft_strlen(val));
			i  = i + 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}

	// printf("%s %c", str, ret);

	// printf("%s", va_arg(ap, char*));

	// printf("%d\n", va_arg(ap, int));
	// printf("%d\n", va_arg(ap, int));
	// printf("%d\n", va_arg(ap, int));

	// printf("%s\n", va_arg(ap, char*));
	// printf("%s\n", va_arg(ap, char*));
	va_end(ap);
	return (0);
}

// int main()
// {
// 	ft_printf("This %d doesnt do shit\n", 900);
// 	return (0);
// }