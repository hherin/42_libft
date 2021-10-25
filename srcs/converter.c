#include "../inc/libft.h"

int		ft_atoi(const char *str)
{
	long	nb;
	int		signe;

	nb = 0;
	signe = 1;
	while ((*str < 14 && *str >= 9) || *str == 32)
		str++;
	signe = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * signe);
}

int ft_toupper(int c)
{
	return (ft_isalpha(c) && (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c);
}

int ft_tolower(int c)
{
	return (ft_isalpha(c) && (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c);
}