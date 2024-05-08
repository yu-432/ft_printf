/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/08 14:12:03 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned long long nb, int upper)
{
	int			count;
	const char	*hex_digits;

	count = 0;
	if (upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (nb >= 16)
		count = put_hex(nb / 16, upper);
	count += write(1, &hex_digits[nb % 16], 1);
	return (count);
}

int	put_pointer(unsigned long long p)
{
	int	l_count;

	l_count = 0;
	l_count += write(1, "0x", 2);
	if (p == 0)
	{
		l_count += write(1, "0", 1);
		return (l_count);
	}
	else
		l_count += put_hex(p, 0) - 1;
	l_count += write(1, "\0", 1);
	return (l_count);
}