#include "ft_printf.h"
#include "libft.h"

int		ft_precis(const char *restrict format, va_list ap, t_flags *f)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	if (*format == '.')
	{
		++i;
		++format;
		if (*format == '*')
			f->prec = va_arg(ap, int);
		else
		{
			while (ft_isdigit(*format))
			{
				precision *= 10;
				precision += *format - '0';
				++format;
				++i;
			}
			f->prec = precision;
		}
	}
	return (i);
}
