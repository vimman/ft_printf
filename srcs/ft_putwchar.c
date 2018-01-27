#include "ft_printf.h"

int	ft_mask1(wchar_t c, char *str)
{
	c = (unsigned)c << 26 >> 26 ^ c >> 6 << 8;
	c = 0xC080 ^ c;
	str[1] = c << 24 >> 24;
	str[0] = c >> 8;
	return (2);
}

int	ft_mask2(wchar_t c, char *str)
{
	c = (unsigned)c << 26 >> 26 ^ c >> 6 << 8;
	c = (unsigned)c << 18 >> 18 ^ c >> 14 << 16;
	c = 0xE08080 ^ c;
	str[2] = (unsigned)c << 24 >> 24;
	str[1] = (unsigned)c << 16 >> 24;
	str[0] = (unsigned)c << 8 >> 24;
	return (3);
}

int	ft_mask3(wchar_t c, char *str)
{
	c = (unsigned)c << 26 >> 26 ^ c >> 6 << 8;
	c = (unsigned)c << 18 >> 18 ^ c >> 14 << 16;
	c = (unsigned)c << 10 >> 10 ^ c >> 22 << 24;
	c = 0xF0808080 ^ c;
	str[3] = (unsigned)c << 24 >> 24;
	str[2] = (unsigned)c << 16 >> 24;
	str[1] = (unsigned)c << 8 >> 24;
	str[0] = c >> 24;
	return (4);
}

int	ft_putwchar(wchar_t c, int fd)
{
	char	str[5];
	int		ret;

	ret = 0;
	ft_bzero(str, 5);
	if (!(c >> 7))
	{
		str[0] = c;
		ret = 1;
	}
	else if (!(c >> 11))
		ret = ft_mask1(c, str);
	else if (!(c >> 16))
		ret = ft_mask2(c, str);
	else if (!(c >> 24))
		ret = ft_mask3(c, str);
	ft_putbuf(str, fd);
	return (ret);
}

int	ft_putwstr(wchar_t *str, int fd)
{
	int ret;

	ret = 0;
	while (*str)
		ret += ft_putwchar(*str++, fd);
	return (ret);
}
