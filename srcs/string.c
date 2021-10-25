#include "../inc/libft.h"

size_t ft_strlen(const char *s)
{
	int i = -1;

	while (s[++i]);
	return (size_t)i;
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0, \
	ret = ft_strlen(src), \
	len = (!dstsize) ? 0 : dstsize - 1;

	while (src[i] && i < len) {
		dst[i] = src[i];
		i++;
	}
	(dstsize) ? dst[i] = '\0' : 0;
	return ret;
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char *d = dst;
	const char *s = src;
	size_t n = dstsize, dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = dstsize - dlen;
	if (n == 0)
		return(dlen + ft_strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return(dlen + (s - src));
}

char *ft_strdup(const char *s1)
{
	char *new;
	size_t i = 0;
	
	if (!s1)
		return NULL;
	if (!(new= malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return NULL;
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return new;
}