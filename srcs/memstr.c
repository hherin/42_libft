#include "../inc/libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	for (size_t i = 0; i < len; i++)
		((char*)b)[i] = c;
	return b;
}

void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	for (size_t i = 0; i < n; i++)
		((char*)dst)[i] = ((char*)src)[i];
	return dst;
}

void *ft_memmove(void *dest, const void *src, size_t len)
{
	char *d = dest;
	const char *s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		char const *lasts = s + (len-1);
		char *lastd = d + (len-1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return dest;
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *s1_cpy = (char*)s1, *s2_cpy = (char*)s2;

	while (n-- > 0 && *s1_cpy && *s2_cpy){
		printf("n = %zu %c - %c\n", n, *s1_cpy, *s2_cpy);
		if (ft_strncmp(s1_cpy, s2_cpy, 1)){
			printf("diff %c - %c\n", *s1_cpy, *s2_cpy);
			return *s1_cpy < *s2_cpy ? -1 : 1;
		}
	}
	return 0;
}


void *ft_memchr(const void *s, int c, size_t n)
{
	char *r = (char*)s;

	while (--n && *r != (char)c)
		r++;
	return (*r == (char)c) ? r : NULL;
}
