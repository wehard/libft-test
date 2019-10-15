/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:25:50 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/15 21:27:06 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINUNIT_H
# define MINUNIT_H

# define mu_assert(message, test) do { if (!(test)) return message; } while (0)
# define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

extern int tests_run;

#endif