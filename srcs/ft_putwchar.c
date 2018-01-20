#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_mask1(wchar_t c, char *str)
{
		c = (unsigned)c << 26 >> 26 ^ c >> 6 << 8;
		c = 0xC080 ^ c;
		str[1] = c << 24 >> 24;
		str[0] = c >> 8;
}

void	ft_mask2(wchar_t c, char *str)
{
		c = (unsigned)c << 26 >> 26 ^ c >> 6 << 8;
		c = (unsigned)c << 18 >> 18 ^ c >> 14 << 16;
		c = 0xE08080 ^ c;
		str[2] = (unsigned)c << 24 >> 24;
		str[1] = (unsigned)c << 16 >> 24;
		str[0] = (unsigned)c << 8 >> 24;
}

void	ft_mask3(wchar_t c, char *str)
{
		c = (unsigned)c << 26 >> 26 ^ c >> 6 << 8;
		c = (unsigned)c << 18 >> 18 ^ c >> 14 << 16;
		c = (unsigned)c << 10 >> 10 ^ c >> 22 << 24;
		c = 0xF0808080 ^ c;
		str[3] = (unsigned)c << 24 >> 24;
		str[2] = (unsigned)c << 16 >> 24;
		str[1] = (unsigned)c << 8 >> 24;
		str[0] = c >> 24;
}

void	ft_putwchar(wchar_t c)
{
	char	str[5];

	ft_bzero(str, 5);
	if (!(c >> 7))
		str[0] = c;
	else if (!(c >> 11))
		ft_mask1(c, str);
	else if (!(c >> 16))
		ft_mask2(c, str);
	else if (!(c >> 24))
		ft_mask3(c, str);
	ft_putbuf(str, 1);
}

void	ft_putwstr(wchar_t *str)
{
	while (*str)
		ft_putwchar(*str++);
}
