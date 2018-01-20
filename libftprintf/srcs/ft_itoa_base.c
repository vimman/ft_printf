#include "libft.h"

char    *ft_itoa_base(int value, int base)
{
	char		*base_char;
	char		*ret;
	long int	tmp;
	int			i;
	int			signe;

	tmp = value;
	i = 0;
	signe = 0;
	base_char = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (tmp /= base)
		++i;
	tmp = value;
	if (tmp < 0)
	{
		i++;
		signe = 1;
		tmp = -tmp;
	}
	ret = (char*)malloc(sizeof(char) * i + 1);
	ret[i + 1] = '\0';
	while (i >=0)
	{
		ret[i] = base_char[tmp % base];
		i--;
		tmp /= base;
	}
	if (signe)
		ret[0] = '-';
	return (ret);
}
