#include <stdio.h>
#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"

int	main(void)
{
	printf("factorial of 4: %d\n", ft_iterative_factorial(4));
	printf("factorial of -4: %d\n", ft_iterative_factorial(-4));
	printf("factorial of 0: %d\n", ft_iterative_factorial(0));
	printf("factorial of 9: %d\n", ft_iterative_factorial(9));
	printf("\n");
	printf("factorial of 4: %d\n", ft_recursive_factorial(4));
	printf("factorial of -4: %d\n", ft_recursive_factorial(-4));
	printf("factorial of 0: %d\n", ft_recursive_factorial(0));
	printf("factorial of 9: %d\n", ft_recursive_factorial(9));
	printf("\n");
	printf("0 power 0 should be 1: %d\n", ft_iterative_power(0, 0));
	printf("2 power 0 should be 1: %d\n", ft_iterative_power(2, 0));
	printf("0 power 2 should be 0: %d\n", ft_iterative_power(0, 2));
	printf("0 power -2 should be 0: %d\n", ft_iterative_power(0, -2));
	printf("-2 power 0 should be 1: %d\n", ft_iterative_power(-2, 0));
	printf("-4 power 2 should be 16: %d\n", ft_iterative_power(-4, 2));
	printf("-4 power -2 should be 0: %d\n", ft_iterative_power(-4, -2));
	printf("4 power 2 should be 16: %d\n", ft_iterative_power(4, 2));
	printf("\n");
	printf("0 power 0 should be 1: %d\n", ft_recursive_power(0, 0));
	printf("2 power 0 should be 1: %d\n", ft_recursive_power(2, 0));
	printf("0 power 2 should be 0: %d\n", ft_recursive_power(0, 2));
	printf("0 power -2 should be 0: %d\n", ft_recursive_power(0, -2));
	printf("-2 power 0 should be 1: %d\n", ft_recursive_power(-2, 0));
	printf("-4 power 2 should be 16: %d\n", ft_recursive_power(-4, 2));
	printf("-4 power -2 should be 0: %d\n", ft_recursive_power(-4, -2));
	printf("4 power 2 should be 16: %d\n", ft_recursive_power(4, 2));
	printf("-3 power 8 should be 6561: %d\n", ft_recursive_power(3, 8));
	printf("-5 power 7 should be -78125: %d\n", ft_recursive_power(-5, 7));
	printf("7 power 6 should be 117649: %d\n", ft_recursive_power(7, 6));
	printf("\n");
	for (int i = -2; i < 10; i++)
	{
		printf("fib index %d: %d", i, ft_fibonacci(i));
		printf("\n");
	}
	printf("\n");
	printf("sqrt of 0 is: %d", ft_sqrt(0));
	printf("\n");
	printf("sqrt of -1 is: %d", ft_sqrt(-1));
	printf("\n");
	printf("sqrt of -16 is: %d", ft_sqrt(-16));
	printf("\n");
	printf("sqrt of 1 is: %d", ft_sqrt(1));
	printf("\n");
	printf("sqrt of 16 is: %d", ft_sqrt(16));
	printf("\n");
	printf("sqrt of 4 is: %d", ft_sqrt(4));
	printf("\n");
	printf("sqrt of 3 is: %d", ft_sqrt(3));
	printf("\n");

	for (int i = -16; i <= 100; i++)
	{
		printf("sqrt of %d is: %d", i, ft_sqrt(i));
		printf("\n");
	}

	printf("is -5 prime: %d", ft_is_prime(-5));
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("is %d prime: %d", i, ft_is_prime(i));
		printf("\n");
	}
	printf("\n");


	return (0);
	printf("next prime of ... is: %d\n", ft_find_next_prime(2));

	for (int i = -5; i <= 100000; i++)
	{
		printf("next prime of %d is: %d\n", i, ft_find_next_prime(i));
	}

}
