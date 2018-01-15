#include "ft_printf.h"
#include "libft.h"

int		ft_fwidth(const char *restrict format, t_flags *f)
{
	int	width;
	int	i;

	(void)f;
	width = 0;
	i = 0;
	while (ft_isdigit(*format))
	{
		width *= 10;
		width += *format - '0';
		++format;
		++i;
	}
	if (width > 0)
		f->min_w = width;
	return (i);
}
