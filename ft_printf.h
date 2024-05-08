/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:45:28 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/08 14:01:17 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		until_per_str(const char *start);
int		if_per(const char *start, va_list ap, int count);
int		put_hex(unsigned long long nb, int upper);
int		put_pointer(unsigned long long p);
int		put_str(char *s);
int		put_c(int c);
int		put_unsign_int(long nb);
int 	put_nbr(int n);

#endif