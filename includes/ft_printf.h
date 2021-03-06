#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include "libft.h"

# define BUFFSIZE 256

# define SHARP	1<<0
# define ZERO	1<<1
# define MINUS	1<<2
# define SPACE	1<<3
# define PLUS	1<<4
# define SEPAR	1<<5

# define WIDTH	1<<6
# define PRECIS	1<<7

# define STAR	1<<8
# define DOT	1<<9
# define LONG	1<<10
# define LLONG	1<<11
# define MOD_H	1<<12
# define MOD_HH	1<<13

typedef struct	s_flags
{
	int			fd;
	int			opts;

	size_t		prec;
	size_t		min_w;
	size_t		ret;
	size_t		len;
}				t_flags;

int				ft_putbuf(char *str, int fd);

int				ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap);

char			*ft_ltoa(long n);
int				ft_flags(const char *restrict format, t_flags *f);
int				ft_fwidth(const char *restrict format, va_list ap, t_flags *f);
int				ft_precis(const char *restrict format, va_list ap, t_flags *f);
int				ft_length(const char *restrict format, t_flags *f);
int				ft_ident(const char *restrict format, va_list ap, t_flags *f);
int				ft_printf(const char *restrict format, ...);
int				ft_d(va_list ap, t_flags *f);
int				ft_c(va_list ap, t_flags *f);
int				ft_s(char const *restrict format, va_list ap, t_flags *f);
int				ft_f(va_list ap, t_flags *f);
int				ft_putwstr(wchar_t *str, int fd);

#endif
