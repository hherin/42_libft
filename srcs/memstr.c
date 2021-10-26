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

void *ft_memcpy(void *dst, const void *src, size_t n)
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

	while (n--)
		if (ft_strncmp(s1_cpy++, s2_cpy++, 1))
			return (unsigned char)s1_cpy[-1] < (unsigned char)s2_cpy[-1] ? -1 : 1;
	return 0;
}


void *ft_memchr(const void *s, int c, size_t n)
{
	char *r = (char*)s;

	while (--n && *r != (char)c)
		r++;
	return (*r == (char)c) ? r : NULL;
}

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char *str_src = src;
    char *str_dst = dst;

	while (n--)
	{
		*str_dst++ = *str_src++;
		if ((unsigned char)str_src[-1] == (unsigned char)c)
			return (void*)str_dst;		
	}
	return NULL;
}

void *ft_calloc(size_t count, size_t size)
{
	char *new;

	if (!(new = malloc(count * size)))
		return NULL;
	ft_memset(new, 0, size * count);
	return new;
}