#include <ft_printf.h>

void	foo(char fmt, va_list ap)
{
	int		d;
	char	c;
	char	*s;

	switch(fmt)
	{
		case 's':
			s = va_arg(ap, char*);
			printf("%s\n", s);
			break;
		case 'd':
			d = va_arg(ap, int);
			printf("%d\n", d);
			break;
		case 'c':
			c = va_arg(ap, int);
			printf("char %c\n", c);
			break;
	}
	va_end(ap);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		c;
	char		option;

	va_start(ap, format);
	while (*format)
	{
		c = *format;
		if (c != '%')
			write(1, &c, 1);
		else
		{
			option = *(++format);
			foo(option, ap);
		}
		format++;
	}
	va_end(ap);
	return (1);
}
