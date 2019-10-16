/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:27:33 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/16 11:18:57 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minunit.h"
#include "../libft/libft.h"

#define BUFSIZE 50

int tests_run = 0;

static char *test_ft_atoi()
{
	char *str = "-123";
	mu_assert("error: ft_strlen failed!", atoi(str) == ft_atoi(str));
	return 0;
}

static char *test_ft_bzero()
{
	char str1[BUFSIZE];
	char str2[BUFSIZE];

	memset(str1, 'x', BUFSIZE);
	memset(str2, 'x', BUFSIZE);

	bzero(str1, 20);
	ft_bzero(str2, 20);

	mu_assert("error: ft_bzero failed!", memcmp(str1, str2, BUFSIZE) == 0);
	return 0;
}

static char *test_ft_isalnum()
{
	char c = '1';
	mu_assert("error: ft_isalnum failed!", ft_isalnum(c) == 1);
	return (0);
}

static char *test_ft_isalpha()
{
	char c = 'a';
	mu_assert("error: ft_isalnum failed!", ft_isalpha(c) == 1);
	return (0);
}

static char *test_ft_isascii()
{
	char c = '1';
	mu_assert("error: ft_isalnum failed!", ft_isascii(c) == 1);
	return (0);
}

static char *test_ft_isdigit()
{
	char c = '1';
	mu_assert("error: ft_isalnum failed!", ft_isdigit(c) == 1);
	return (0);
}

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
	mu_run_test(test_ft_atoi);
	mu_run_test(test_ft_bzero);

	mu_run_test(test_ft_isalnum);
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isascii);
	mu_run_test(test_ft_isdigit);

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
