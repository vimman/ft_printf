#include "ft_printf.h"
#include "libft.h"

int		ft_precis(const char *restrict format, va_list ap, t_flags *f)
{
	int	i;
	int	precision;

	(void)f;
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
			f->prec = va_arg(ap, int);
			printf("%d", (int)f->prec);
		}
		else
		{
			while (ft_isdigit(*format))
			{
				precision *= 10;
				precision += *format - '0';
				++format;
				++i;
			}
		}
		printf("%d]", precision);
	}
	return (i);
}
