/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:48:58 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/08 16:21:14 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *s)
{
	int	len;

	if (!s)
		len = write(1, "(null)", 6);
	else
	{
		len = ft_strlen(s);
		write(1, s, len);
	}
	return (len);
}

int	put_unsign_int(long nb)
{
	char	a;
	int		i;

	i = 0;
	if (nb >= 10)
		i += put_unsign_int(nb / 10);
	a = (nb % 10) + '0';
	i += write (1, &a, 1);
	return (i);
}

int	put_nbr(int n)
{
	char	a;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i += write(1, "-", 1);
	}
	if (n >= 10)
	{
		i += put_nbr(n / 10);
	}
	a = (n % 10) + '0';
	i += write (1, &a, 1);
	return (i);
}
