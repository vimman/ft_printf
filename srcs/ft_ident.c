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

void	ft_S(va_list ap, t_flags *f)
{
	(void)f;
	return (ft_putwstr(va_arg(ap, wchar_t *), f->fd));
}

int		ft_s(va_list ap, t_flags *f)
{
	(void)f;
	return (ft_putbuf(va_arg(ap, char *), f->fd));
}

int		ft_d(va_list ap, t_flags *f)
{
	char	*fr;

	if (f->opts & LONG) //TODO don't forget to free
		ft_putbuf((fr = ft_ltoa(va_arg(ap, long int))), f->fd);
	else
		ft_putbuf((fr = ft_itoa(va_arg(ap, int))), f->fd);
	free(fr);
	return (4);
}

int		ft_ident(const char *restrict format, va_list ap, t_flags *f)
{
	if (*format == 'd')
		ft_d(ap, f);
	else if (*format == 's')
		ft_s(ap, f);
	else if (*format == 'S')
		ft_S(ap, f);
	else if (*format == 'c')
		ft_c(ap, f);
	else if (*format == '%')
		ft_putbuf("%", f->fd);
	//if (*format == 'f')
	//	ft_f(ap, f);
	return (1);
}


