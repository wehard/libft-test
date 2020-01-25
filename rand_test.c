/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:51:53 by wkorande          #+#    #+#             */
/*   Updated: 2020/01/25 13:55:01 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	int seed = 12345;
	for (size_t i = 0; i <= 100; i++)
	{
		ft_printf("%-3d: %f\n", i, ft_rand_d(&seed));
	}
	return (0);
}
