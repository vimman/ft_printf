#include <stdio.h>

int	ft_printf(const char *restrict format, ...);

int		main(void)
{
	printf("real printf\t: ");
	printf("hello %s yolo", "you");
	printf("\nft_printf\t: ");
	ft_printf("hello %s yolo", "you");
	printf("\n\n");

	printf("real printf\t: ");
	printf("hello %i", 42);
	printf("\nft_printf\t: ");
	ft_printf("hello %i", 42);
	printf("\n\n");

	printf("real printf\t: ");
	printf("hello %ld", 21474836480);
	printf("\nft_printf\t: ");
	ft_printf("hello %ld", 21474836480);
	printf("\n\n");

	printf("real printf\t: ");
	printf("hello %f", 21474.86480);
	printf("\nft_printf\t: ");
	ft_printf("hello %f", 21474.86480);
	printf("\n\n");

	printf("real printf\t: ");
	printf("hello %#12.3F", 21474.8648098989);
	printf("\nft_printf\t: ");
	ft_printf("hello %#12.3jF", 21474.8648098989);
	printf("\n\n");

}
