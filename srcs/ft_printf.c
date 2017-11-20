#include "ft_printf.h"
#include "libft.h"

int		ft_flags(const char *restrict format)
{
	if (*format == '-')
		printf("[flag -] ");
	else if (*format == '0')
		printf("[flag 0] ");
	else if (*format == '+')
		printf("[flag +] ");
	else if (*format == ' ')
		printf("[flag space] ");
	else if (*format == '#')
		printf("[flag #] ");
	else
		return (0);
	return (1);
}

int		ft_fwidth(const char *restrict format)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (ft_isdigit(*format))
	{
		width *= 10;
		width += *format - '0';
		++format;
		++i;
	}
	printf("[field width is %d] ", width);
	return (i);
}

int		ft_precis(const char *restrict format)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	if (*format == '.')
	{
		++i;
		++format;
		printf("[precision is ");
		if (*format == '*')
		{
			++i;
			printf("*]");
		}
		while (ft_isdigit(*format))
		{
			precision *= 10;
			precision += *format - '0';
			++format;
			++i;
		}
		printf("%d]", precision);
	}
	return (i);
}

int		ft_length(const char *restrict format)
{
	int		i;
	char	*clen;

	i = 0;
	if (*format == 'h')
	{
		++format;
		++i;
		if (*format == 'h')
		{
			++format;
			++i;
			clen = "hh";
		}
		else
			clen = "h";
	}
	else if (*format == 'l')
	{
		++format;
		++i;
		if (*format == 'l')
		{
			++format;
			++i;
			clen = "ll";
		}
		else
			clen = "l";
	}
	else if (*format == 'j')
	{
		++format;
		++i;
		clen = "j";
	}
	else
		return (0);
	printf("[length is %s]", clen);
	return (i);
}

int		ft_ident(format)
{
	(void)format;
	return (0);
}

int		ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap)
{
	int		ret;
	int		i;
	char	*buf[BUFFSIZE];

	i = 0;
	ret = 0;
	(void)stream;
	(void)ap;
	(void)buf;
	while (*format)
	{
		while (*format && *format != '%')
		{
			printf("%c", *format);
			ret++;
			format++;
		}
		if (*format == '%')
		{
			++format;
			format += ft_flags(format);
			format += ft_fwidth(format);
			format += ft_precis(format);
			format += ft_length(format);
	//		format += ft_ident(format);
		}
	}
	return (ret);
}

int	ft_printf(const char *restrict format, ...)
{
	int		ret;
	va_list	arg;

	va_start(arg, format);
	ret = ft_vfprintf(stdout, format, arg);
	va_end(arg);
	return (ret);
}
