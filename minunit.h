/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:25:50 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/16 12:16:53 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINUNIT_H
# define MINUNIT_H

# define mu_assert(testname, message, test) do { if (!(test)) return message; else printf("%s:\t \033[0;32mOK\033[0m\n", testname); } while (0)
# define mu_run_test(test) do { char *message = test(); num_tests++; if (message) return message; } while (0)
//# define mu_test_ok(test) printf("test: \033[0;32mOK\033[0m\n")

extern int num_tests;

#endif
