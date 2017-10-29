#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 256

typedef union	u_union
{
	char	c;
	short	i;
	long	l;
	float	f;
	double	d;
	char	*s;
}				t_union;

int				ft_vfprintf(FILE *restrict stream,
		const char *restrict format, va_list ap);
int				ft_printf(const char *restrict format, ...);
#endif
