#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 256

#define MINUS	1
#define PLUS	1<<1
#define SHARP	1<<2
#define ZERO	1<<3
#define SPACE	1<<4
#define WIDTH	1<<5
#define STAR	1<<6
#define DOT		1<<7
#define LONG	1<<8
#define LLONG	1<<9

typedef struct	s_flags
{
	int			opts;

	size_t		prec;
	size_t		min_w;
	size_t		ret;
}				t_flags;

int				ft_putbuf(char *str, int fd);

int				ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap);

char			*ft_ltoa(long n);
int				ft_flags(const char *restrict format, t_flags *f);
int				ft_fwidth(const char *restrict format, t_flags *f);
int				ft_precis(const char *restrict format, t_flags *f);
int				ft_length(const char *restrict format, t_flags *f);
int				ft_ident(const char *restrict format, va_list ap, t_flags *f);
int				ft_printf(const char *restrict format, ...);
#endif
