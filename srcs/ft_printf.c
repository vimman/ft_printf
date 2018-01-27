#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int		ret;
	va_list	arg;

	va_start(arg, format);
	ret = ft_vfprintf(stdout, format, arg);
	va_end(arg);
	return (ret);
}
