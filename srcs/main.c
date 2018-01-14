#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *restrict format, ...);

int		main(void)
{
	ft_printf("ft_printf\t: ");
	ft_printf("hello %s yolo\n", "you");
	printf("real printf\t: ");
	printf("hello %s yolo", "you");
	printf("\n\n");

	ft_putstr("\nft_printf\t: ");
	ft_printf("hello %d\n", 42);
	printf("real printf\t: ");
	printf("hello %d\n", 42);
	printf("\n\n");

	ft_putstr("\nft_printf\t: ");
	ft_printf("hello %ld\n", 9223372036854775807);
	printf("real printf\t: ");
	printf("hello %ld\n", 9223372036854775807);
	//printf("oups %.5d\n", 23432357);
	printf("\n\n");

	ft_printf("ft_printf\t: ");
	ft_printf("hello %s yolo\n", "👾");
	printf("real printf\t: ");
	printf("hello %s yolo", "👾");
	printf("\n\n");
//
//	printf("real printf\t: ");
//	printf("hello %f", 21474.86480);
//	printf("\nft_printf\t: ");
//	ft_printf("hello %f", 21474.86480);
//	printf("\n\n");
//
//	printf("real printf\t: ");
//	printf("hello %#12.3F", 21474.8648098989);
//	printf("\nft_printf\t: ");
//	ft_printf("hello %#12.3jF", 21474.8648098989);
//	printf("\n\n");

}
