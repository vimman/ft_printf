#include "ft_printf.h"
#include "libft.h"
int		ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap)
{
	int		ret;
	int		i;
	char	tmp[BUFFSIZE];
	t_flags	f;


	(void)stream;
	ret = 0;
	f.opts = 0;
	f.prec = 0;
	f.min_w = 0;
	while (*format)
	{
		i = 0;
		while (*format && *format != '%')
			tmp[i++] = (char)*format++;
		ret = ft_putbuf(tmp, 1);
		bzero(tmp, ft_strlen(tmp));
		if (*format == '%')
		{
			++format;
			format += ft_flags(format, &f);
			format += ft_fwidth(format, &f);
			format += ft_precis(format, &f);
			format += ft_length(format, &f);
			format += ft_ident(format, ap, &f);
		}
	}
	(void)f;
	//f.opts = f.opts & PLUS;
	//ft_putbuf(ft_itoa_base(f.opts, 2), (int)stream);
	ft_putbuf(NULL, 1);
	return (ret);
}

