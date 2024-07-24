/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/09 16:12:09 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned long long nb, int upper)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count = put_hex(nb / 16, upper);
	if (upper)
		count += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[nb % 16], 1);
	return (count);
}

int	put_pointer(unsigned long p)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (p == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	else
		count += put_hex(p, 0);
	return (count);
}
