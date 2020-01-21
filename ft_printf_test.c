/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:19:49 by wkorande          #+#    #+#             */
/*   Updated: 2020/01/15 11:18:10 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	main(void)
{
	char *buf;
	//ft_bzero(buf, 500);
	ft_printf("hello world\n");

	//ft_sprintf(buf, "%.3f %.3f %.3f\n", 100.0, 9.0, 11.0);
	buf = ft_dtoa(10.0, 3);
	ft_putendl(buf);
	return (0);
}
