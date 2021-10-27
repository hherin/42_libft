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

static int		ft_nblen(unsigned int nb)
{
	int len = 0;

	if (nb >= 0 && nb < 10)
		return 1;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return len;
}

char			*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	nb;

	len = (n < 0) ? ft_nblen(-n) + 1 : ft_nblen(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	nb = n;
	if (n < 0)
	{
		*str = '-';
		nb = -n;
	}
	*(str + len--) = '\0';
	while (len > (*str == '-' ? 0 : -1))
	{
		if (nb > 9)
		{
			str[len--] = (nb % 10) + '0';
			nb /= 10;
		}
		else
			str[len--] = nb + '0';
	}
	return (str);
}