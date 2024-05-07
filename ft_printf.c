/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:34:39 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/07 17:52:44 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"

static void	to_hex_rec(unsigned long long p, char *hex, int i)
{
	if (p == 0)
		return ;
	to_hex_rec(p / 16, hex, i + 1);
	hex[13 - i] = "0123456789abcdef"[p % 16];
}

static void	put_hex(unsigned int nb, int upper)
{
	if (nb == 0)
		return ;
	put_hex(nb / 16, upper);
	if (upper)
		write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else
		write(1, &"0123456789abcdef"[nb % 16], 1);
}

static void	put_pointer(unsigned long long p)
{
	char	hex[13];

	write(1, "0x", 2);
	if (p == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else
	{
		to_hex_rec(p, hex, 2);
		hex[12] = '\0';
	}
	write(1, hex, 13);
}

static void	put_str(char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
}

static void	put_c(int c)
{

	write(1, &c, 1);
}

static int	until_per_str(const char *start)
{
	int	i;

	i = 0;
	while (start[i] != '%' && start[i])
		i++;
	write(1, start, i);
	return (i);
}

static int put_unsign_int(long nb)
{
	char	a;

	if (nb >= 10)
	{
		put_unsign_int(nb / 10);
	}
	a = (nb % 10) + '0';
	write (1, &a, 1);
	return (0);
}

static void	if_per(const char *start, va_list ap)
{
	if (*start == 'c')
		put_c(va_arg(ap, int));
	if (*start == 's')
		put_str(va_arg(ap, char *));
	if (*start == 'p')
		put_pointer((unsigned long long)va_arg(ap, void *));
	if (*start == 'd' || *start == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	if (*start == 'u')
		put_unsign_int((long)va_arg(ap, unsigned int));
	if (*start == 'x')
		put_hex(va_arg(ap, unsigned int), 0);
	if (*start == 'X')
		put_hex(va_arg(ap, unsigned int), 1);
	if (*start == '%')
		write(1, "%", 1);
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
			start += until_per_str(start);
		if (*start == '%')
		{
			start++;
			if_per(start, ap);
		}
		start++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	char point[] = "abc";
	printf("%c\n%s\n%p\n%d\n%i\n%ld\n%x\n%X\n%%\n", 'x', "yyyy", point,\
		123456789, 123456789, 4294967293, 123456788, 283479754);
	ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%a\n", 'x', "yyyy", point,\
		123456789, 123456789, 4294967293, 123456788, 283479754);
	return (0);
}