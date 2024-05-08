/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:34:39 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/08 14:15:05 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	until_per_str(const char *start)
{
	int	l_count;

	l_count = 0;
	while (start[l_count] != '%' && start[l_count])
		l_count++;
	write(1, start, l_count);
	return (l_count);
}

int	if_per(const char *start, va_list ap, int count)
{
	if (*start == 'c')
		count += put_c(va_arg(ap, int));
	else if (*start == 's')
		count += put_str(va_arg(ap, char *));
	else if (*start == 'p')
		count += put_pointer((unsigned long long)va_arg(ap, void *));
	else if (*start == 'd' || *start == 'i')
		count += put_nbr(va_arg(ap, int));
	else if (*start == 'u')
		count += put_unsign_int((long)va_arg(ap, unsigned int));
	else if (*start == 'x')
		count += put_hex(va_arg(ap, unsigned int), 0);
	else if (*start == 'X')
		count += put_hex(va_arg(ap, unsigned int), 1);
	else if (*start == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*start;
	int			count;

	count = 0;
	va_start(ap, format);
	start = format;
	while (*start)
	{
		if (*start != '%')
			count += put_c(*start);
		else if (*start == '%')
		{
			start++;
			count = if_per(start, ap, count);
		}
		start++;
	}
	va_end(ap);
	return (count);
}
