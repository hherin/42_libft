#include "../inc/libft.h"

char *ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (!*s)
			return NULL;
		s++;
	}
	return (char*)s;
}

char *ft_strrchr(const char *s, int c)
{
	int i = ft_strlen(s) + 1;
	char *r = (char*)s;

	while (i-- > 0)
		if (r[i] == c)
			return r + i;
	return NULL;
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *cpy1 = (char*)s1, *cpy2 = (char*)s2;

	while (n--)
		if (*cpy1++ != *cpy2++)
			return ((unsigned char)cpy1[-1] < (unsigned char)cpy2[-1]) ? -1 : 1;
	return 0;
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0;

	if (!needle)
		return (char*)haystack;
	while (len-- && *haystack++)
	{
		i = -1;
		while (haystack[i] == needle[i + 1] && (int)(len - i) >= 0)
			i++;
		if (i + 1 == ft_strlen(needle))
			return (char*)(&haystack[-1]);
	}
	return NULL;
}