#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int is_sign(char c)
{
    if (c == '%' || c == '*' || c == '+' || c == '-' || c == '/')
        return(1);
    return(0);
}
void addition(int i, int j)
{
    printf("%d\n", (i + j));
}
void soustrac(int i, int j)
{
    printf("%d\n", i - j);
}
void mult(int i, int j)
{
    printf("%d\n", i * j);
}
void ft_div(int i, int j)
{
    printf("%d\n", i / j);
}
void modulo(int i, int j)
{
    printf("%d\n", i % j);
}
int main(int ac, char **av)
{
    void (*cal[5])(int, int) = {
		modulo,mult,addition,
		soustrac,ft_div};
    if (ac == 4)
    {
        char count = 0;
        int i = -1;
        while (count++ < av[2][0])
            if (is_sign(count))
            {
                i++;
                printf("%d\n", i);
            }
        (*cal[i])(atoi(av[1]), atoi(av[3]));
    }
    else
        write(1, "\n", 1);
    return (0);
}
