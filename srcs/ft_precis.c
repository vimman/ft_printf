#include "ft_printf.h"
#include "libft.h"

int		ft_precis(const char *restrict format, t_flags *f)
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
