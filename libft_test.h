/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:25:50 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/12 11:46:51 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

# define w_assert(testname, message, test)\
do\
{\
	if (!(test))\
	{\
		printf("\033[0;34m%-23s\033[0;31m[FAIL]\033[0m\t", testname);\
		return message;\
	}\
	else\
		printf("\033[0;34m%-25s\033[0;32m[OK]\033[0m\n", testname);\
}\
while (0)

# define w_run_test(test)\
do\
{\
	char *message = test();\
	num_tests++;\
	if (message)\
	{\
		num_fail++;\
		return message;\
	}\
	else\
		num_ok++;\
}\
while (0)

extern int num_tests;
extern int num_ok;
extern int num_fail;

#endif
