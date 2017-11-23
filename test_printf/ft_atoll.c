#include <unistd.h>
#include <stdio.h>
#include "../../../libft/libft.h"

long int ft_atol(char *str)
{
	long long result;
	int negatif;

	result = 0;
	negatif = 1;
	while(ft_space(*str))
		str++;
	if (*str == '-')
		negatif = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
			str++;
	}
	return (result * negatif);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%ld", ft_atol(av[1]));
	}
	return (0);
}
