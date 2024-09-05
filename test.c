#include "ft_printf.h"
#include "stdio.h"

int main(void)
{
	printf(" = %d\n", ft_printf("%s %s %d %p", "Hello", "tkondo", 27, "test"));
	printf(" = %d\n", printf("%s %s %d %p", "Hello", "tkondo", 27, "test"));

	int (*f)(const char *,...);
	f=ft_printf;
	f("[%d]\n",f("%c, %c, %c", '5', 'x', 'n'));
	f=printf;
	f("[%d]\n",f("%c, %c, %c", '5', 'x', 'n'));
}
