/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:27:33 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/20 17:31:02 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft_test.h"
#include "../libft/libft.h"

#define BUFSIZE 50
#define DEBUG 0

int num_tests = 0;
int num_ok = 0;
int num_fail = 0;

#pragma region PART 1 LIBC

static char *test_ft_atoi()
{
	char *str = "-123";
	int a = atoi(str);
	int b = ft_atoi(str);
#if DEBUG
	printf("\n");
	printf("atoi:    %i\n", a);
	printf("ft_atoi: %i\n", b);
#endif
	mu_assert("ft_atoi", "error: ft_atoi failed!", a == b);
	mu_assert("ft_atoi_+548", "failed with \"+548\"!", ft_atoi("+548") == 548);
	mu_assert("ft_atoi_47", "failed with \"47\"!", ft_atoi("47") == 47);
	mu_assert("ft_atoi_--47", "failed with \"--47\"!",  atoi("--47") == ft_atoi("--47"));

/*
	char	n[40] = "99999999999999999999999999";
	int		i1 = atoi(n);
	int		i2 = ft_atoi(n);
#if DEBUG
	ft_putchar('\n');
	ft_putstr("atoi:    ");
	ft_putnbr(i1);
	ft_putchar('\n');
	ft_putstr("ft_atoi: ");
	ft_putnbr(i2);
	ft_putchar('\n');
#endif
	mu_assert("ft_atoi_long+", "failed with over long max value", i1 == i2);
	*/
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
	mu_assert("ft_isalnum", "basic test failed!", ft_isalnum(c) == 1);
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
	mu_assert("ft_memmove_basic", "error: ft_memmove failed!", memcmp(buf1, buf2, 10) == 0);
	memmove(NULL, NULL, 5);
	ft_memmove(NULL, NULL, 5);
	mu_assert("ft_memmove_null", "failed with (null, null, 5)", memmove(NULL, NULL, 5) == ft_memmove(NULL, NULL, 5));
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

static char *test_ft_strchr()
{
	char str[] = "test basic ft_strchr !";
	char c = 'f';

	mu_assert("ft_strchr", "error: ft_strchr failed!", strchr(str, c) == ft_strchr(str, c));
	return (0);
}

static char *test_ft_strrchr()
{
	char str[] = "test basic ft_strrchr !";
	char c = 'f';

	mu_assert("ft_strrchr", "error: ft_strrchr failed!", strrchr(str, c) == ft_strrchr(str, c));
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

#ifdef __APPLE__
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
#endif

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

#ifdef __APPLE__
static char *test_ft_strnstr()
{
	char str[] = "this is a string and we want to find something in it";
	char needle[] = "is";
	int n = 3;
#if DEBUG
	printf("%s\n", strnstr(str, needle, n));
	printf("%s\n", ft_strnstr(str, needle, n));
#endif
	mu_assert("ft_strnstr", "error: ft_strnstr failed!", strnstr(str, needle, n) == ft_strnstr(str, needle, n));
	return (0);
}
#endif

static char *test_ft_strstr()
{
	char str[] = "this is a string and we want to find something in it";
	char needle[] = "string";
	mu_assert("ft_strstr", "error: ft_strstr failed!", strstr(str, needle) == ft_strstr(str, needle));
	return (0);
}

static char *test_ft_tolower()
{
	mu_assert("ft_tolower (alpha)", "error: ft_strstr failed!", ft_tolower('C') == 'c');
	mu_assert("ft_tolower (nprint)", "error: ft_strstr failed!", ft_tolower('\n') == '\n');
	return (0);
}

static char *test_ft_toupper()
{
	mu_assert("ft_toupper (alpha)", "failed basic test with alpha", ft_toupper('c') == 'C');
	mu_assert("ft_toupper (nprint)", "failed test with \'\\r\'", ft_toupper('\r') == '\r');
	return (0);
}




static char *all_tests_libc() {
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
	mu_run_test(test_ft_strchr);
	mu_run_test(test_ft_strcmp);
	mu_run_test(test_ft_strcpy);
	mu_run_test(test_ft_strdup);

#ifdef __APPLE__
	mu_run_test(test_ft_strlcat);
#else
	printf("Skipping ft_strlcat!\n");
#endif

	mu_run_test(test_ft_strlen);
	mu_run_test(test_ft_strncat);
	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_strncpy);

#ifdef __APPLE__
	mu_run_test(test_ft_strnstr);
#else
	printf("Skipping ft_strnstr!\n");
#endif

	mu_run_test(test_ft_strrchr);
	mu_run_test(test_ft_strstr);
	mu_run_test(test_ft_tolower);
	mu_run_test(test_ft_toupper);

	return 0;
}

#pragma endregion

#pragma region PART 2 ADDITIONAL

static char *test_ft_itoa()
{
	mu_assert("ft_itoa_zero", "failed with 0", strcmp(ft_itoa(0), "0") == 0);
	mu_assert("ft_itoa_pos", "failed with 12345", strcmp(ft_itoa(12345), "12345") == 0);
	mu_assert("ft_itoa_neg", "failed with -12345", strcmp(ft_itoa(-12345), "-12345") == 0);
	return (0);
}

static char *test_ft_strmapi()
{
	char *str;
	char *strmapi;
	str = (char *)malloc(sizeof(*str) * 12);
	strcpy(str, "LoReM iPsUm");
	//strmapi = ft_strmapi(str, &mapi);
	return (0);
}

static char *test_ftstrnequ()
{
	mu_assert("ft_strnequ_zero", "should be true, was false", ft_strnequ("abcd", "zxyw", 0) == 1);
	return (0);
}

static char *test_ft_strtrim()
{
	char *str = "   hello   ";
	char *result;
	result = ft_strtrim(str);
#if DEBUG
	printf("src: %s\n", str);
	printf("res: %s\n", result);
#endif
	//mu_assert("ft_strtrim_basic", "failed with \"  hello   \"", strcmp(result, "hello") == 0);
	//mu_assert("ft_strtrim_empty", "failed with \"\"", strcmp(ft_strtrim(""), "") == 0);
	mu_assert("ft_strtrim_blank", "failed with \"   \"", strcmp(ft_strtrim("   "), "") == 0);
	return (0);
}

static char *test_ft_strsplit()
{
	char *str = "one two three";
	char **res = ft_strsplit(str, 'x');
	int c = 0;
	while (res[c] != 0)
		c++;

	mu_assert("ft_strsplit_basic", "failed with \"one two three\"", c == 1);
	//mu_assert("ft_strsplit_empty", "failed with \"\"", ft_strsplit("", ' ') == 0);
	return (0);
}

static char *all_tests_additional()
{
	mu_run_test(test_ft_itoa);
	mu_run_test(test_ft_strtrim);
	mu_run_test(test_ft_strsplit);
	mu_run_test(test_ftstrnequ);
	return (0);
}
#pragma endregion

#pragma region EXTRA

static char *test_ft_nwords()
{
	mu_assert("ft_nwords_1", "failed with \"hello world\"", ft_nwords("hello world", ' ') == 2);
	mu_assert("ft_nwords_2", "failed with \"helloworld\"", ft_nwords("helloworld", ' ') == 1);
	return (0);
}

static char *test_ft_ndigits()
{
	mu_assert("ft_ndigits_pos", "failed with 1234", ft_ndigits(1234) == 4);
	mu_assert("ft_ndigits_neg", "failed with -1234", ft_ndigits(1234) == 4);
	return (0);
}

static char *all_tests_extra()
{
	mu_run_test(test_ft_nwords);
	mu_run_test(test_ft_ndigits);
	return (0);
}

#pragma endregion


static char *all_tests_bonus()
{
	return (0);
}

void	init()
{
	num_tests = 0;
	num_ok = 0;
	num_tests = 0;
}

void	print_result()
{
	int w = 23;
	printf("\u2554");
	for (size_t i = 0; i < w; i++)
		printf("\u2500");
	printf("\u2557\n");

	printf("\u2502  Total:\t%d\t\u2502\n", num_tests);
	printf("\u2502  Success:\t%i\t\u2502\n", num_ok);
	printf("\u2502  Fail:\t%i\t\u2502\n", num_fail);

	printf("\u255A");
	for (size_t i = 0; i < w; i++)
		printf("\u2500");
	printf("\u255D\n");
	printf("\n");
	init();
}

int libc_success = 0;
int add_success = 0;
int bonus_success = 0;
int extra_success = 0;

static int run_test(char *name, char*(*test)(void))
{
	printf("Running tests for %s\n", name);
	char *result = test();
	if (result != 0)
	{
		printf("%s\n", result);
	}
	print_result();
	return (result != 0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		libc_success = run_test("PART 1", all_tests_libc);
		add_success = run_test("PART 2", all_tests_additional);
	}
	else
	{
		if (strcmp(argv[1], "1") == 0)
			libc_success = run_test("PART 1", all_tests_libc);
		if (strcmp(argv[1], "2") == 0)
			add_success = run_test("PART 2", all_tests_additional);
		if (strcmp(argv[1], "b") == 0)
			bonus_success = run_test("BONUS", all_tests_bonus);
		if (strcmp(argv[1], "x") == 0)
			extra_success = run_test("EXTRA", all_tests_extra);
	}

	if ((libc_success == 0) && (add_success == 0) && (bonus_success == 0) && (extra_success == 0))
	{
		const char* user = getenv("USER");
		printf("\t\t\t\033[0;32m[ALL OK]\033[0m\n");
		printf("Great job, %s!\n", user);
	}

	return ((libc_success != 0) || (add_success != 0) || (bonus_success != 0) || (extra_success != 0));
}
