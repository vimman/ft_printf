#include <unistd.h>
#include "libft.h"

#define BUFFSIZE 10

int		ft_putbuf(char *str, int fd)
{
	static char	buf[BUFFSIZE];
	static int	k = -1;
	int			len;

	len = 0;
	ft_bzero(buf, BUFFSIZE);
	if (str == NULL)
	{
		len = ft_strlen((char*)buf);
		write(fd, buf, len);
	}
	while(*str)
	{
		while(*str && k < BUFFSIZE)
		{
			buf[++k] = *str;
			++str;
		}
		if (k == BUFFSIZE)
		{
			write(fd, buf, BUFFSIZE);
			ft_bzero(buf, BUFFSIZE);
			k = -1;
		}
	}
	return(len);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	ft_putbuf(argv[1], 1);
}
