#include "../inc/libft.h"

static size_t	ft_word_btw_sep(const char *s1, char sep)
{
	size_t		count = 0;

	while (*s1)
	{
		char *save = (char*)s1;
		while (*s1 && *s1 != sep)
			s1++;
		(save != s1) ? count++ : 0;
		while (*s1 && *s1 == sep)
			s1++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);

	size_t  words = ft_word_btw_sep(s, c);
	size_t i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);

	while (words--)
	{
		size_t lenght = 0;
		while (*s && *s == c)
			s++;
		while (s[lenght] && s[lenght] != c)
			lenght++;
		tab[i++] = ft_substr(s, 0, lenght);
		s += lenght;
	}
	tab[i] = NULL;
	return (tab);
}