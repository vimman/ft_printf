#include "ft_printf.h"
#include "libft.h"

int		ft_fwidth(const char *restrict format, va_list ap, t_flags *f)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	if (*format == '*')
	{
		f->min_w = va_arg(ap, int);
		return (1);
	}
	while (ft_isdigit(*format))
	{
		width *= 10;
		width += *format - '0';
		++format;
		++i;
	}
	if (width > 0)
	{
		f->min_w = width;
		f->opts ^= WIDTH;
	}
	return (i);
}
