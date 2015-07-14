#include "ft_ls.h"

void	ft_putnstr(int max, char *str)
{
	int i;

	i = 0;
	while ((int)(ft_strlen(str) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str);
	ft_putstr(" ");
}

void	ft_putnnbr(int max, int info)
{
	int	i;

	i = 0;
	while ((nblen(info) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(info);
	ft_putchar(' ');
}

void	ft_putstr_b(char *str)
{
	ft_putstr(BOLD);
	ft_putstr(str);
	ft_putstr(RESET);
}

int		nblen(int len)
{
	int		i;

	i = (len <= 0 ? 1 : 0);
	while (len)
	{
		len = len / 10;
		++i;
	}
	return (i);
}

void	print_folder(char *str)
{
	ft_putstr(str);
	ft_putstr(":\n");
}