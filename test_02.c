#include <stdio.h>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
/* #include "ex12/ft_print_memory.c" */

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"

void	test_00(void)
{
	printf("%s[ex00]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char src[5] = { 'a', 'b', 'c', 'd', '\0' };
	char dest[5];
	ft_strcpy(dest, src);
	printf("%sexpected:", KBLU);
	for (int i = 0; i < 5; i++)
	{
		if (src[i] == '\0')
			printf("%s\\0", KBLU);
		else
			printf("%s%c", KBLU, src[i]);
	}
	printf("\n");
	printf("%sgot:", KCYN);
	for (int j = 0; j < 5; j++)
	{
		if (dest[j] == '\0')
			printf("%s\\0", KCYN);
		else
			printf("%s%c", KCYN, dest[j]);
	}
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char src2[5] = { 'a', '\0', '\0', '\0', '\0' };
	char dest2[5];
	ft_strcpy(dest2, src2);
	printf("%sexpected:", KBLU);
	for (int i = 0; i < 5; i++)
	{
		if (src2[i] == '\0')
			printf("%s\\0", KBLU);
		else
			printf("%s%c", KBLU, src2[i]);
	}
	printf("\n");
	printf("%sgot:", KCYN);
	for (int j = 0; j < 5; j++)
	{
		if (dest2[j] == '\0')
			printf("%s \\0", KCYN);
		else
			printf("%s%c", KNRM, dest2[j]);

	}
	printf("\n");
}

void	test_01(void)
{
	printf("%s[ex01]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	unsigned int n = 6;
	char dest[n];
	ft_strncpy(dest, "abc", n);
	printf("%sexpected:", KBLU);
	printf("%s abc", KNRM);
	printf("\n");
	printf("%sgot:", KCYN);
	for (int i = 0; i < (int) n; i++)
	{
		printf("%s%c", KNRM, dest[i]);
	}
	printf("\n");
}

void	test_02(void)
{
	printf("%s[ex02]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[7] = { 'a', 'Z', 'b', 'A', 'z', 'Y', '\0' };
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_alpha(str));
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[7] = { 'a', 'Z', '0', '[', 'z', 'Y', '\0' };
	printf("%sexpected: 0", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_alpha(str2));
	printf("\n");
	printf("%s======TEST 3======\n", KNRM);
	char str3[7] = "";
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_alpha(str3));
	printf("\n");
}

void	test_03(void)
{
	printf("%s[ex03]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[5] = { '0', '1', '2', '9', '\0' };
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_numeric(str));
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[5] = { 'a', 'b', 'A', '9', '\0' };
	printf("%sexpected: 0", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_numeric(str2));
	printf("\n");
	printf("%s======TEST 3======\n", KNRM);
	char str3[5] = "";
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_numeric(str3));
	printf("\n");
}

void	test_04(void)
{
	printf("%s[ex04]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[5] = { 'a', 'z', 'b', 'd', '\0' };
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_lowercase(str));
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[5] = { 'a', 'b', 'A', '9', '\0' };
	printf("%sexpected: 0", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_lowercase(str2));
	printf("\n");
	printf("%s======TEST 3======\n", KNRM);
	char str3[5] = "";
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_lowercase(str3));
	printf("\n");
}

void	test_05(void)
{
	printf("%s[ex05]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[5] = { 'A', 'Z', 'B', 'F', '\0' };
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_uppercase(str));
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[5] = { 'A', 'a', 'z', '9', '\0' };
	printf("%sexpected: 0", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_uppercase(str2));
	printf("\n");
	printf("%s======TEST 3======\n", KNRM);
	char str3[5] = "";
	printf("%sexpected: 1", KBLU);
	printf("\n");
	printf("%sgot: %d", KCYN, ft_str_is_uppercase(str3));
	printf("\n");
}

void	test_06(void)
{
	/* printf("%s[ex06]\n", KYEL); */
	/* printf("%s======TEST 1======\n", KNRM); */
	/* char str[21] = "Coucou tu vas bien ?"; */
	/* printf("%sCoucou tu vas bien ?", KBLU); */
	/* printf("\n"); */
	/* printf("%sexpected: 1", KBLU); */
	/* printf("\n"); */
	/* ft_is_printable(str); */
	/* printf("\n"); */
	/* printf("%s======TEST 2======\n", KNRM); */
	/* char str2[21] = "€ou\ttu vas bien ?"; */
	/* printf("%s€ou\\ttu vas bien ?", KBLU); */
	/* printf("\n"); */
	/* ft_putstr_non_printable(str2); */
	/* printf("\n"); */
	/* printf("%s======TEST 3======\n", KNRM); */
	/* char str3[10] = "あ\na"; */
	/* printf("%sあ\\na", KBLU); */
	/* printf("\n"); */
	/* ft_putstr_non_printable(str3); */
	/* printf("\n"); */
}

void	test_07(void)
{
	printf("%s[ex07]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[6] = { 'a', 'b', 'z', '\0', '\0', '\0' };
	printf("%sexpected: ABZ", KBLU);
	printf("\n");
	ft_strupcase(str);
	printf("%sgot: ", KCYN) ;
	for (int i = 0; i < 6; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[6] = { 'a', 'B', 'Z', '0', '[', '\0' };
	printf("%sexpected: ABZ0[", KBLU);
	printf("\n");
	ft_strupcase(str2);
	printf("%sgot: ", KCYN) ;
	for (int j = 0; j < 6; j++)
	{
		printf("%c", str2[j]);
	}
	printf("\n");
}

void	test_08(void)
{
	printf("%s[ex08]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[6] = { 'A', 'B', 'Z', '\0', '\0', '\0' };
	printf("%sexpected: abz", KBLU);
	printf("\n");
	ft_strlowcase(str);
	printf("%sgot: ", KCYN) ;
	for (int i = 0; i < 6; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[6] = { 'A', 'b', 'z', '0', '[', '\0' };
	printf("%sexpected: abz0[", KBLU);
	printf("\n");
	ft_strlowcase(str2);
	printf("%sgot: ", KCYN) ;
	for (int j = 0; j < 6; j++)
	{
		printf("%c", str2[j]);
	}
	printf("\n");
}

void	test_09(void)
{
	printf("%s[ex09]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[61] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%sexpected: Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un", KBLU);
	printf("\n");
	ft_strcapitalize(str);
	printf("%sgot:      ", KCYN) ;
	for (int i = 0; i < 61; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[17] = "Jjj<be^/l_#1]g7e";
	printf("%sexpected: Jjj<Be^/L_#1]G7e", KBLU);
	printf("\n");
	ft_strcapitalize(str2);
	printf("%sgot:      ", KCYN) ;
	for (int j = 0; j < 17; j++)
	{
		printf("%c", str2[j]);
	}
	printf("\n");
	printf("%s======TEST 3======\n", KNRM);
	char str3[41] = "Ce+Cc!f/q9sj:1mkkpwkgfjoh91>jk2ej#}qh?+;";
	printf("%sexpected: Ce+Cc!F/Q9sj:1mkkpwkgfjoh91>Jk2ej#}Qh?+;", KBLU);
	printf("\n");
	ft_strcapitalize(str3);
	printf("%sgot:      ", KCYN) ;
	for (int k = 0; k < 41; k++)
	{
		printf("%c", str3[k]);
	}
	printf("\n");
}

void	test_10(void)
{
	// src = "0123456789";
	// dest[10];
	// dest should become 012345678
}

void	test_11(void)
{
	printf("%s[ex11]\n", KYEL);
	printf("%s======TEST 1======\n", KNRM);
	char str[21] = "Coucou\ntu vas bien ?";
	printf("%sCoucou\\ntu vas bien ?", KBLU);
	printf("\n");
	ft_putstr_non_printable(str);
	printf("\n");
	printf("%s======TEST 2======\n", KNRM);
	char str2[21] = "€ou\ttu vas bien ?";
	printf("%s€ou\\ttu vas bien ?", KBLU);
	printf("\n");
	ft_putstr_non_printable(str2);
	printf("\n");
	printf("%s======TEST 3======\n", KNRM);
	char str3[10] = "あ\na";
	printf("%sあ\\na", KBLU);
	printf("\n");
	ft_putstr_non_printable(str3);
	printf("\n");
}

void	test_12(void)
{
	// todo
}

void	test_all(void)
{
	test_00();
	test_01();
	test_02();
	test_03();
	test_04();
	test_05();
	test_06();
	test_07();
	test_08();
	test_09();
	test_10();
	test_11();
	test_12();
}

int		main(int argc, char* argv[])
{
	if (argc > 2)
	{
		printf("%stoo many arguments \n", KRED);
		printf("%susage: \"./a.out\" to test all exercises \n", KNRM);
		printf("%susage: \"./a.out 0\" to test specific exercise \n", KNRM);
		return (0);
	}

	if (argc == 1)
	{
		test_all();
		return (0);
	}

	switch ((int)*argv[1] - '0')
	{
		case 0:
			test_00();
			return (0);
		case 1:
			test_01();
			return (0);
		case 2:
			test_02();
			return (0);
		case 3:
			test_03();
			return (0);
		case 4:
			test_04();
			return (0);
		case 5:
			test_05();
			return (0);
		case 6:
			test_06();
			return (0);
		case 7:
			test_07();
			return (0);
		case 8:
			test_08();
			return (0);
		case 9:
			test_09();
			return (0);
		case 11:
			test_11();
			return (0);
		default:
			test_all();
			return (0);
	}
	printf("\n");
	return (0);
}
