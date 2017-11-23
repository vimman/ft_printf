#include "ft_printf.h"
#include "libft.h"

int		ft_flags(const char *restrict format, t_flags *f)
{
	(void)f;
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
