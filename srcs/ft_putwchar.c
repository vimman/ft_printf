#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define BUFFSIZE 10

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

void	ft_putbuf(char	*byt)
{
	static char	buf[BUFFSIZE];
	(void)byt;
	(void)buf;
}

void	ft_putwchar(wchar_t c)
{
	unsigned c1;
	unsigned c2;
	char cc;

	if (!(c >> 7))
	{
		cc = (char)c;
		write(1, &cc, 1);
	}
	else if (!(c >> 11))
	{
		//printf("%d mask1\n", c);
		printf("%x mask1\n", c);
		c = (unsigned int)c << 26 >> 26 ^ c >> 6 << 8;
		c = 0xC080 ^ c;
		c1 = (unsigned int)c >> 8;
		c2 = (unsigned int)c << 24 >> 24;
		printf("c1 %x\n", c1);
		printf("c2 %x\n", c2);
		write(1, &c1, 1);
		write(1, &c2, 1);
		printf("%x\n",c);
		//write(1, &c1, 1);
	}
	//else if (!(c >> 16))
	//{
	//	//printf("%d mask2\n", c);
	//	printf("%x mask2\n", c);
	//	c = (unsigned int)c << 26 >> 26 ^ c >> 6 << 8;
	//	c = c << 18 >> 18 ^ c >> 13 << 15;
	//	c = 0xE08080 ^ c;
	//	//printf("%s\n",ft_itoa_base(c, 2));
	//	write(1, &c, 3);
	//	printf("%x\n",c);
	//}
	//else
	//{
	//	unsigned int	tmp;
	//	printf("%x mask3\n", c);
	//	tmp = (unsigned int)c << 26 >> 26 ^ c >> 6 << 8;
	//	tmp = tmp << 18 >> 18 ^ tmp >> 14 << 16;
	//	tmp = tmp << 10 >> 10 & tmp >> 24 << 26;
	//	tmp = 0xE0808080 ^ tmp;
	//	//printf("%s\n", ft_itoa_base(c, 2));
	//	write(1, &tmp, 4);
	//	printf("%x\n",tmp);
	//}
}

int	main(int argc, char **argv)
{
	wchar_t	*test;

	test = malloc(sizeof(wchar_t*));
	if (argc < 1 && argc > 2)
		return (-1);

	printf("setlocale : %s\n", setlocale(LC_ALL, "fr_FR.UTF-8"));
	printf("MB_CUR_MAX = %d\n", MB_CUR_MAX);

	if (argc > 1)
		*test = (wchar_t)argv[1];
	else
		*test = L'é';
		//test = L'é';
	ft_putwchar(*test);
	//ft_putwchar('\n');
	//printf("%C\n", test);
}
