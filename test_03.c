#include <stdio.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

void	test_00(void)
{
	printf("[ex00]\n");
	char *str00_1 = "abcdef";
	char *str00_2 = "abcdef";
	printf("%d", ft_strcmp(str00_1, str00_2));
	printf("\n");
	char *str00_3 = "abz";
	char *str00_4 = "aby";
	printf("%d", 'z' - 'y');
	printf("\n");
	printf("%d", ft_strcmp(str00_3, str00_4));
	printf("\n");
	char *str00_5 = "abc";
	char *str00_6 = "abd";
	printf("%d", 'c' - 'd');
	printf("\n");
	printf("%d", ft_strcmp(str00_5, str00_6));
	printf("\n");
}

void	test_01()
{
	printf("[ex01]\n");
	char *str00_1 = "abcd";
	char *str00_2 = "abcz";
	printf("%d", ft_strncmp(str00_1, str00_2, 3));
	printf("\n");
	char *str00_3 = "abz";
	char *str00_4 = "aby";
	printf("%d", 'z' - 'y');
	printf("\n");
	printf("%d", ft_strncmp(str00_3, str00_4, 3));
	printf("\n");
	char *str00_5 = "abc";
	char *str00_6 = "abd";
	printf("%d", 'c' - 'd');
	printf("\n");
	printf("%d", ft_strncmp(str00_5, str00_6, 3));
	printf("\n");
}

void	test_02()
{
	printf("[ex02]\n");
	char dest[7] = "zyx";
	char *src = "abc";
	char *res;
	res = ft_strcat(dest, src);
	for (int i = 0; i < 7; i++)
	{
		if (res[i] == '\0')
			printf("\\0");
		else
			printf("%c", res[i]);
	}
	printf("\n");
}

void	test_03()
{
	printf("[ex03]\n");
	char dest[7] = "xyz";
	char *src = "abcdef";
	char *res;
	res = ft_strncat(dest, src, 3);
	for (int i = 0; i < 7; i++)
	{
		if (res[i] == '\0')
			printf("\\0");
		else
			printf("%c", res[i]);
	}
	printf("\n");
}

void	test_04()
{
	printf("[ex04]\n");
	char *str1 = "stay awhile you are so beautiful";
	char *to_find1 = "you";
	char *res1;
	res1 = ft_strstr(str1, to_find1);
	printf("%c", *res1);
	printf("\n");
	printf("%s", res1);
	printf("\n");
	printf("\n");
	char *str2 = "stay awhile\0 you are so beautiful";
	char *to_find2 = "you";
	char *res2;
	res2 = ft_strstr(str2, to_find2);
	if (res2 == '\0' )
		printf("NULL is returned!");
	printf("\n");
	char *to_find3 = "";
	char *res3;
	res3 = ft_strstr(str1, to_find3);
	printf("%s", res3);
	printf("\n");
}

void	test_05()
{
	printf("[ex05]\n");
	char dest[7] = "zyx";
	char *src = "abcdefg";
	unsigned int res;
	res = ft_strlcat(dest, src, 7);
	for (unsigned int i = 0; i < res; i++)
	{
		if (dest[i] == '\0')
			printf("\\0");
		else
			printf("%c", dest[i]);
	}
	printf("\n");
}

int	main(void)
{
	test_00();
	test_01();
	test_02();
	test_03();
	test_04();
	test_05();
	return (0);
}
