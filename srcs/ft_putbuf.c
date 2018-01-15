#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_putbuf(char *str, int fd)
{
	static char	buf[BUFFSIZE + 1];
	static int	k = 0;
	int			len;

	len = 0;
	if (!str)
	{
		write(fd, buf, ft_strlen(buf));
		ft_bzero(buf, BUFFSIZE);
		k = 0;
		return (0);
	}
	while (str && *str)
	{
		while (*str && k < BUFFSIZE)
		{
			++len;
			buf[k++] = *str;
			++str;
		}
		if (k == BUFFSIZE)
		{
			write(fd, buf, BUFFSIZE);
			ft_bzero(buf, BUFFSIZE);
			k = 0;
		}
	}
	return (len);
}
