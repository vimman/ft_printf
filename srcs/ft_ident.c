#include "ft_printf.h"
#include "libft.h"

int		ft_f(va_list ap, t_flags *f)
{
	(void)f;
	(void)ap;
	return (0);
}

int		ft_c(va_list ap, t_flags *f)
{
	(void)f;
	(void)ap;
	if (f->opts & LLONG)
		printf("l flag\n");
	return (0);
}

int		ft_s(va_list ap, t_flags *f)
{
	(void)f;
	return (ft_putbuf(va_arg(ap, char *), 1));
}

int		ft_d(va_list ap, t_flags *f)
{
	if (f->opts & LONG) //TODO don't forget to free
		ft_putbuf(ft_ltoa(va_arg(ap, long int)), 1);
	else
		ft_putbuf(ft_itoa(va_arg(ap, int)), 1);
	return (4);
}

int		ft_ident(const char *restrict format, va_list ap, t_flags *f)
{
	if (*format == 'd')
		ft_d(ap, f);
	if (*format == 's')
		ft_s(ap, f);
	if (*format == 'c')
		ft_c(ap, f);
	//if (*format == 'f')
	//	ft_f(ap, f);
	return (1);
}


