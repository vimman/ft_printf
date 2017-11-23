#include "ft_printf.h"
#include "libft.h"

int		ft_length(const char *restrict format, t_flags *f)
{
	int		i;
	char	*clen;

	(void)f;
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
			f->opts ^= LLONG;
		}
		else
			f->opts ^= LONG;
	}
	else if (*format == 'j')
	{
		++format;
		++i;
		clen = "j";
	}
	else
		return (0);
	return (i);
}
