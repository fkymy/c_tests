#include <stdio.h>
#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"

int	main(void)
{
	char *str = "abcdef";
	int res;
	res = ft_strlen(str);
	printf("%d", res);
	printf("\n");

	ft_putstr(str);
	printf("\n");

	int nb = -2147483648;
	ft_putnbr(nb);
	printf("\n");

	char *str2 = " ---+--+1234ab567";
	int res2;
	res2 = ft_atoi(str2);
	printf("%d", res2);
}
