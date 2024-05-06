/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:34:39 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/06 16:14:11 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static int	put_str(const char *start)
{
	int	i;

	i = 0;
	while (start[i] != '%' && start[i])
		i++;
	write(1, start, i);
	return (i);
}

static void if_per(const char *start, va_list ap)
{
	char *s;

	s = (char *)va_arg(ap, char *);
	printf("%s\n", s);
}
int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*start;

	va_start(ap, format);
	start = format;
	while (*start)
	{
		if (*start != '%')
			start += put_str(start);
		if (*start == '%')
			if_per(start, ap);
		start++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	ft_printf("abcdf%gh%%", "xxxx", "zzzz", "yyyy");
	return (0);
}