/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufukuya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:59:59 by yufukuya          #+#    #+#             */
/*   Updated: 2020/01/22 12:43:03 by yufukuya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
/* #include "ex04/ft_conver_base.c" */
/* #include "ex04/ft_conver_base2.c" */
#include "ex05/ft_split.c"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	printf("[ex00]\n");
	char *src00 = "Stay awhile, you are so beautiful.";
	char *res00 = ft_strdup(src00);
	printf("address of src00: %p\n", src00);
	printf("address of res00: %p\n", res00);
	for (int i = 0; res00[i]; i++)
	{
		printf("%c ", res00[i]);
	}
	free(res00);
	printf("\n");

	printf("[ex01]\n");
	int *res01 = ft_range(-100, 100);
	for (int i = 0; i < 200; i++)
	{
		printf("%d ", res01[i]);
	}
	printf("\n");

	printf("[ex02]\n");

	/* int a = 42; */
	/* int *ptr = &a; */
	/* int **range = &ptr; */
	/* int res02; */
    /*  */
	/* res02 = ft_ultimate_range(range, -100, 100); */
	/* printf("%d\n", res02); */
    /*  */
	/* for (int i = 0; range[i]; i++) */
	/* { */
	/* 	for (int j = 0; j < res02; j++) */
	/* 	{ */
	/* 		printf("%d ", range[i][j]); */
	/* 	} */
	/* } */

	char base_from = "0123456789";
	char base_to = "01";
	char *converted_nbr = ft_convert_base("42", base_from, base_to);
	printf("%s", converted_nbr);

	char *strs[] = { "Stay", "awhile", "you", "are", "so", "beautiful" };
	char *sep = "____vakjga;djfkas___";
	char *res03 = ft_strjoin(6, strs, sep);
	int i = -1;
	while (res03[++i])
		write(1, &res03[i], 1);



	char *str = "xpQHquONfkmJciOyniBGJ5qon PmMW";
	char *charset = "RTM0";
	/* char *str = "stay awhile you are so beautuful"; */
	/* char *charset = " "; */
	char **res = ft_split(str, charset);
	int i = 0;
	int j = 0;
	int wc = ft_get_wc(str, charset);
	printf("printing out **res! \n");
	while (i < wc)
	{
		j = 0;
		while (res[i][j])
		{
			printf("%c ", res[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(res);
	return (0);
}
