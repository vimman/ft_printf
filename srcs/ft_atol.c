#include <unistd.h>
#include <stdio.h>
#include "libft.h"

long int ft_atol(char *str)
{
	long int result;
	int negatif;

	result = 0;
	negatif = 1;
	while(ft_isspace(*str))
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
