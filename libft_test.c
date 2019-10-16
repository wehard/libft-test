/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:27:33 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/16 15:42:46 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minunit.h"
#include "../libft/libft.h"

#define BUFSIZE 50
#define DEBUG 0

int num_tests = 0;

static char *test_ft_atoi()
{
	char *str = "-123";
	mu_assert("ft_atoi", "error: ft_atoi failed!", atoi(str) == ft_atoi(str));
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

	mu_assert("ft_bzero", "error: ft_bzero failed!", memcmp(str1, str2, BUFSIZE) == 0);
	return 0;
}

static char *test_ft_isalnum()
{
	char c = '1';
	mu_assert("ft_isalnum", "error: ft_isalnum failed!", ft_isalnum(c) == 1);
	return (0);
}

static char *test_ft_isalpha()
{
	char c = 'a';
	mu_assert("ft_isalpha", "error: ft_isalpha failed!", ft_isalpha(c) == 1);
	return (0);
}

static char *test_ft_isascii()
{
	char c = '1';
	mu_assert("ft_isascii", "error: ft_isascii failed!", ft_isascii(c) == 1);
	return (0);
}

static char *test_ft_isdigit()
{
	char c = '1';
	mu_assert("ft_isdigit", "error: ft_isdigit failed!", ft_isdigit(c) == 1);
	return (0);
}

static char *test_ft_isprint()
{
	char c = '1';
	mu_assert("ft_isprint", "error: ft_isprint failed!", ft_isprint(c) == 1);
	return (0);
}

static char *test_ft_memccpy()
{
	char src[] = "test basic memccpy !";
	char buf1[20];
	char buf2[20];

	memccpy(buf1, src, 'x', 10);
	ft_memccpy(buf2, src, 'x', 10);

	mu_assert("ft_memccpy", "error: ft_memccpy failed!", memcmp(buf1, buf2, 10) == 0);
	return (0);
}

static char *test_ft_memchr()
{
	char str[] = "test basic ft_memchr !";
	char c = 'f';

	mu_assert("ft_memchr", "error: ft_memchr failed!", memchr(str, c, 15) == ft_memchr(str, c, 15));
	return (0);
}

static char *test_ft_memcmp()
{
	char *s1 = "hello world!";
	char *s2 = "hello world!";
	int n = 5;

	mu_assert("ft_memcmp", "error: ft_memcmp failed!", memcmp(s1, s2, n) == ft_memcmp(s1, s2, n));
	return (0);
}

static char *test_ft_memmove()
{
	char src[] = "test basic memcpy !";
	char buf1[19];
	char buf2[19];

	memmove(buf1, src, 10);
	ft_memmove(buf2, src, 10);

	mu_assert("ft_memmove", "error: ft_memmove failed!", memcmp(buf1, buf2, 10) == 0);
	return (0);
}

static char *test_ft_memcpy()
{
	char src[] = "test basic memcpy !";
	char buf1[19];
	char buf2[19];

	memcpy(buf1, src, 10);
	ft_memcpy(buf2, src, 10);

	mu_assert("ft_memcpy", "error: ft_memcpy failed!", memcmp(buf1, buf2, 10) == 0);
	return (0);
}

static char *test_ft_memset()
{
	char buf1[BUFSIZE];
	char buf2[BUFSIZE];

	memset(buf1, 'X', BUFSIZE);
	memset(buf2, 'X', BUFSIZE);

	memset(buf1, 'O', BUFSIZE);
	ft_memset(buf2, 'O', BUFSIZE);

	mu_assert("ft_memset", "error: ft_memset failed!", memcmp(buf1, buf2, 10) == 0);
	return (0);
}

static char *test_ft_strcat()
{
	char src[] = "I am a cat";
	char buf1[BUFSIZE] = "blabla";
	char buf2[BUFSIZE] = "blabla";

	strcat(buf1, src);
	ft_strcat(buf2, src);
	mu_assert("ft_strcat", "error: ft_strcat failed!", strcmp(buf1, buf2) == 0);
	return (0);
}

static char *test_ft_strcmp()
{
	char *s1 = "hello world!";
	char *s2 = "hello world!";
	mu_assert("ft_strcmp", "error: ft_strcmp failed!", strcmp(s1, s2) == ft_strcmp(s1, s2));
	return 0;
}

static char *test_ft_strcpy()
{
	char	*src = "hello this is a\n\r";
	char	dst1[30];
	char	dst2[30];

	memset(dst1, 'A', sizeof(dst1));
	memset(dst2, 'A', sizeof(dst2));

	strcpy(dst1, src);
	ft_strcpy(dst2, src);

	mu_assert("ft_strcpy", "error: ft_strcpy failed!", strcmp(dst1, dst2) == 0);
	return 0;
}

static char *test_ft_strdup()
{
	char *src = "I want to be duplicated!";
	char dup[BUFSIZE];

	ft_strcpy(dup, src);

	mu_assert("ft_strdup", "error: ft_strdup failed!", strcmp(src, dup) == 0);
	return 0;
}

static char *test_ft_strlcat()
{
	char src[] = "I am a cat";
	char buf1[BUFSIZE] = "blabla";
	char buf2[BUFSIZE] = "blabla";

	strlcat(buf1, src, 5);
	ft_strlcat(buf2, src, 5);
	mu_assert("ft_strlcat", "error: ft_strlcat failed!", strcmp(buf1, buf2) == 0);
	return (0);
}

static char *test_ft_strlen()
{
	mu_assert("ft_strlen", "error: ft_strlen failed!", strlen("123") == ft_strlen("123"));
	return 0;
}

static char *test_ft_strncat()
{
	char src[] = "I am a cat";
	char buf1[BUFSIZE] = "blabla";
	char buf2[BUFSIZE] = "blabla";

	strncat(buf1, src, 5);
	ft_strncat(buf2, src, 5);
	mu_assert("ft_strncat", "error: ft_strncat failed!", strcmp(buf1, buf2) == 0);
	return (0);
}

static char *test_ft_strncmp()
{
	char *s1 = "hello world!";
	char *s2 = "hello world!";
	int n = 5;

	mu_assert("ft_strncmp", "error: ft_strncmp failed!", strncmp(s1, s2, n) == ft_strncmp(s1, s2, n));
	return 0;
}

static char *test_ft_strncpy()
{
	char	*src = "hello this is a";
	char	dst1[30];
	char	dst2[30];
	int n = 10;

	memset(dst1, 'A', sizeof(dst1));
	memset(dst2, 'A', sizeof(dst2));

	strncpy(dst1, src, n);
	ft_strncpy(dst2, src, n);

#if DEBUG
	printf("strncopy:\t%s\n", dst1);
	printf("ft_strncpy:\t%s\n", dst2);
#endif

	mu_assert("ft_strncpy", "error: ft_strncpy failed!", memcmp(dst1, dst2, 29) == 0);
	return 0;
}

static char *test_ft_strstr()
{
	char str[] = "this is a string and we want to find something in it";
	char needle[] = "string";
	mu_assert("ft_strstr", "error: ft_strstr failed!", strcmp(strstr(str, needle), ft_strstr(str, needle)) == 0);
	return (0);
}

static char *test_ft_tolower()
{
	mu_assert("ft_tolower", "error: ft_strstr failed!", ft_tolower('C') == 'c');
	return (0);
}

static char *test_ft_toupper()
{
	mu_assert("ft_toupper", "error: ft_toupper failed!", ft_toupper('c') == 'C');
	return (0);
}

// Part 1
static char *all_tests() {
	mu_run_test(test_ft_atoi);
	mu_run_test(test_ft_bzero);

	mu_run_test(test_ft_isalnum);
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isascii);
	mu_run_test(test_ft_isdigit);
	mu_run_test(test_ft_isprint);

	mu_run_test(test_ft_memccpy);
	mu_run_test(test_ft_memchr);
	mu_run_test(test_ft_memcmp);
	mu_run_test(test_ft_memcpy);
	mu_run_test(test_ft_memmove);
	mu_run_test(test_ft_memset);

	mu_run_test(test_ft_strcat);
	mu_run_test(test_ft_strcmp);
	mu_run_test(test_ft_strcpy);
	mu_run_test(test_ft_strdup);
	mu_run_test(test_ft_strlcat);
	mu_run_test(test_ft_strlen);
	mu_run_test(test_ft_strncat);

	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_strncpy);

	mu_run_test(test_ft_strstr);

	mu_run_test(test_ft_tolower);
	mu_run_test(test_ft_toupper);

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
		printf("\033[0;32mALL OK!\033[0m\nGreat job, %s!\n", user);
	}
	printf("Tests run: %d\n", num_tests);

	return result != 0;
}
