#include "../inc/libft.h"

char *ft_strchr(const char *s, int c)
{
	int i = -1;
	char *r = (char*)s;

	while (r && r[++i])
		if (r[i] == c)
			return r + i;
	return NULL;
}

char *ft_strrchr(const char *s, int c)
{
	int i = ft_strlen(s);
	char *r = (char*)s;

	while (i > -1)
		if (r[i] == c)
			break;
	return r + i;
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char *cpy1 = (char*)s1, *cpy2 = (char*)s2;

	while (n--)
		if (*cpy1++ != *cpy2++)
			return (cpy1[-1] < cpy2[-1])? -1 : 1;
	return 0;
}

char *ft_strstr(const char *haystack, const char *needle)
{
	size_t i = 0, j = 0;
	char *hay_cpy = (char*)haystack;

	if (!needle)
		return hay_cpy;
	while (hay_cpy && hay_cpy[i])
	{
		j = 0;
		while (hay_cpy[i++] == needle[j++])
		;
		if (needle[j] == '\0')
			return hay_cpy + i - j + 1;
		else if (j)
			i -= j - 1;
	}
	return NULL;
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0, j = 0;
	char *hay_cpy = (char*)haystack;

	if (!needle)
		return hay_cpy;
	while (hay_cpy && hay_cpy[i])
	{
		j = 0;
		while (hay_cpy[i++] == needle[j++] && j < len)
		;
		if (j == len)
			return hay_cpy + i - j + 1;
		else if (j)
			i -= j - 1;
	}
	return NULL;
}