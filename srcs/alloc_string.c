#include "../inc/libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (s && start > ft_strlen(s))
		return ft_calloc(sizeof(char), 1);
	if (!(new = ft_calloc(sizeof(char), len + 1)) || !s)
		NULL;
	ft_memcpy(new, s + start, len);
	return new;
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	int len1 = ft_strlen(s1), len2 = ft_strlen(s2);
	if (!(new = ft_calloc(sizeof(char), len1 + len2 + 1)))
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	return new;
}

char *ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return NULL;
	
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_t end = ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, s1[end]))
		end--;
	return ft_substr(s1, 0, end + 1);
}

