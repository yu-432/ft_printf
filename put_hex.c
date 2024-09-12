/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:39:36 by yooshima          #+#    #+#             */
/*   Updated: 2024/09/12 22:19:42 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex(unsigned long nb, int upper)
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
	if (p == 0 && count == 0)
		return(write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += put_hex(p, 0);
	return (count);
}
