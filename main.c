/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:40:51 by yooshima          #+#    #+#             */
/*   Updated: 2024/05/08 10:45:03 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
    char *test;
    int value_ft;
    int value_orgin;

    value_ft = ft_printf("hello world\n");
    value_orgin = printf("hello world\n");
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("c: %c\n", 'a');
    value_orgin = printf("c: %c\n", 'a');
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("s: %s\n", "hello world");
    value_orgin = printf("s: %s\n", "hello world");
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("p: %p\n", test);
    value_orgin = printf("p: %p\n", test);
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("d: %d\n", 123456);
    value_orgin = printf("d: %d\n", 123456);
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("i: %i\n", 123456);
    value_orgin = printf("i: %i\n", 123456);
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("-u: %u u: %u\n", -123456, 123456);
    value_orgin = printf("-u: %u u: %u\n", -123456, 123456);
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("x: %x X: %X\n", 123456, 123456);
    value_orgin = printf("x: %x X: %X\n", 123456, 123456);
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);
    printf("\n");

    value_ft = ft_printf("%%%%%\n");
    value_orgin = printf("%%%%%\n");
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("INT_MAX: %d INT_MIN: %d\n", INT_MAX, INT_MIN);
    value_orgin = printf("INT_MAX: %d INT_MIN: %d\n", INT_MAX, INT_MIN);
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("%");
    printf("\n");
    value_orgin = printf("%");

    printf("\n");

    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

	value_ft = ft_printf("%\n");
    value_orgin = printf("%\n");
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

	printf("\n");

    value_ft = ft_printf("%r%w%b%m%\n");
    value_orgin = printf("%r%w%b%m%\n");
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

    printf("\n");

    value_ft = ft_printf("%r%w%b%m%%%\n");
    value_orgin = printf("%r%w%b%m%%%\n");
    printf("ft_printf: %d\n", value_ft);
    printf("   printf: %d\n", value_orgin);

	printf("\n");
}

// 	int main()
// {
//     char *test;
//     int value_ft;
//     int value_orgin;

// 	value_ft = ft_printf("abc%r\n");
//     value_orgin = printf("abc%r\n");
//     printf("ft_printf: %d\n", value_ft);
//     printf("   printf: %d\n", value_orgin);

//     printf("\n");

//     printf("\n");
// }

// #include <stdio.h>
// #include "printf.h"

// int main(){
// 	printf("own:");
// 	fflush(NULL);
// 	int a = ft_printf("%");
// 	printf("\n");
// 	printf("lib:");
// 	int b = printf("%");


// 	printf("\n");
// 	printf("own:");
// 	fflush(NULL);
// 	int c = ft_printf("%r%r%r%r");
// 		printf("\n");
// 	printf("lib:");
// 	int d = printf("%r%r%r%r");	
// 	printf("\n");
// 	printf("a:%d, \nb:%d, \nc:%d, \nd:%d\n",a,b,c,d);
// 	return (0);

// }
