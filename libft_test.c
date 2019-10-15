/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:27:33 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/15 22:55:26 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minunit.h"
#include "../libft/libft.h"

int tests_run = 0;

static char *test_ft_strcmp()
{
	char *s1 = "hello world!";
	char *s2 = "hello world!";
	mu_assert("error: ft_strcmp failed!", strcmp(s1, s2) == ft_strcmp(s1, s2));
	return 0;
}

static char *test_ft_strlen()
{
	mu_assert("error: ft_strlen failed!", strlen("123") == ft_strlen("123"));
	return 0;
}

/*
static char *test_ft_memset()
{
	char buffer1[5] = "12345";
	char buffer2[5] = "12345";
	char c = 'x';
	mu_assert("error: ft_memset failed!", (char*)memset(buffer1, c, 2) == (char*)memset(buffer2, c, 2));
	return 0;
}
*/

static char *test_ft_strcpy()
{
	char	*src = "--> nyancat <--\n\r";
	char	dst1[30];
	char	dst2[30];

	memset(dst1, 'A', sizeof(dst1));
	memset(dst2, 'A', sizeof(dst2));

	strcpy(dst1, src);
	ft_strcpy(dst2, src);

	mu_assert("error: ft_strcpy failed!", strcmp(dst1, dst2) == 0);
	return 0;
}

static char *all_tests() {
	 mu_run_test(test_ft_strcmp);
	 mu_run_test(test_ft_strlen);
	 mu_run_test(test_ft_strcpy);
	 return 0;
}

int main(void/*int argc, char **argv*/)
{
	char *result = all_tests();
	if (result != 0) {
		 printf("%s\n", result);
	}
	else
	{
		const char* user = getenv("USER");
		printf("ALL TESTS PASSED!\nGreat job, %s!\n", user);
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
