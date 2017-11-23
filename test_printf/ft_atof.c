#include <unistd.h>
#include <stdio.h>
#include "../../../libft/libft.h"

double ft_atof(char *str)
{
	double result;
	int sign;
  double i;

	result = 0;
	sign = 1;
  i = 0.1;
	while(ft_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + ((*str++ - '0'));
  if (*str++ == '.')
  {
    while (*str >= '0' && *str <= '9')
    {
      result = result + (i * (*str++ - '0'));
      i = i / 10;
    }
  }
	return ((double)(result * sign));
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
    printf("%.15f\n", atof(av[1]));
		printf("%.15f", ft_atof(av[1]));
	}
	return (0);
}
