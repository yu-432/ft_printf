
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlcat(char *dst, char *src, size_t dstsize)
{
    size_t            dst_len;
    size_t            src_len;
    unsigned long    i;

    i = 0;
    if (dstsize == 0)
        return (strlen(src));
    dst_len = strlen(dst);
    src_len = strlen(src);
    if (dstsize <= dst_len)
        dst_len = dstsize;
    else
	{
        while (i < dstsize - dst_len - 1 && *src)
        {
            dst[i + dst_len] = src[i];
            i++;
        }
        dst[i] = '\0';
	}
    return (src_len + dst_len);
}

int main(void)
{


	char str3[10] = "abc";
	char str4[] = "def";
	printf("str = %s, len = %lu\n", str3, strlcat(str3, str4, 8));
	char str1[10] = "abc";
	char str2[] = "def";
	printf("str = %s, len = %lu\n", str1, ft_strlcat(str1, str2, 8));







	printf("aaa\n");

	return (0);
}