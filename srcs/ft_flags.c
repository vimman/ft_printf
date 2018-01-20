#include "libft.h"
#include "ft_printf.h"

int		ft_flags(const char *restrict format, t_flags *f)
{
	if (*format == '-')
		f->opts ^= MINUS;
	else if (*format == '0')
		f->opts ^= ZERO;
	else if (*format == '+')
		f->opts ^= PLUS;
	else if (*format == ' ')
		f->opts ^= SPACE;
	else if (*format == '#')
		f->opts ^= SHARP;
	else
		return (0);
	return (1);
}
