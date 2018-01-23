#include "ft_printf.h"
#include "libft.h"

int		ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap)
{
	int		ret;
	int		i;
	char	tmp[BUFFSIZE];
	t_flags	f;


	ret = 0;
	f.opts = 0;
	f.prec = 0;
	f.min_w = 0;
	f.fd = stream->_file;
	ft_bzero(tmp, BUFFSIZE);
	while (*format)
	{
		i = -1;
		while (*format && *format != '%')
			tmp[++i] = (char)*format++;
		ft_putbuf(tmp, f.fd);
		ft_bzero(tmp, BUFFSIZE);
		if (*format == '%')
		{
			++format;
			format += ft_flags(format, &f);
			format += ft_fwidth(format, ap, &f);
			format += ft_precis(format, ap, &f);
			format += ft_length(format, &f);
			format += ft_ident(format, ap, &f);
		}
	}
	(void)f;
	//f.opts = f.opts & PLUS;
	//ft_putbuf(ft_itoa_base(f.opts, 2), (int)stream);
	//ret += ft_putbuf("", f.fd);
	ret = ft_putbuf(NULL, f.fd);
	return (ret);
}


