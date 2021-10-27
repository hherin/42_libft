#include "../inc/libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	nb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}