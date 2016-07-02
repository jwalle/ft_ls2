#include "ft_ls.h"

int		error(char c)
{
	if (!strchr(OPTIONS, c))
	{
		ft_putstr("ft_ls: illegal option -- '");
		ft_putchar(c);
		ft_putstr("'\n");
		ft_putstr("usage: ls [-lRartAdgGinSvs1-] ");
		ft_putstr("[file ...]\n");
		return (1);
	}
	return (0);
}

int		options(char *av, t_opt *opt)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (error(av[i]))
			return (0);
		if (av[1] == '-') // error si -l
		{
			opt->end = 1;
			return (1);
		}
		if (av[i] == 'l' || av[i] == 'G' || av[i] == 'g' || av[i] == 'n')
			opt->l = 1;
		if (av[i] == 'a')
			opt->a = 1;
		if (av[i] == 'r')
			opt->r = 1;
		i++;
	}
	return (options2(av, opt));
}

int		options2(char *av, t_opt *opt)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 'd')
			opt->d = 1;
		if (av[i] == 'g')
			opt->g = 1;
		if (av[i] == 'G')
			opt->G = 1;
		if (av[i] == 'i')
			opt->i = 1;
		if (av[i] == 'n')
			opt->n = 1;
		if (av[i] == 'v')
			opt->v = 1;
		if (av[i] == 'A')
			opt->A = 1;
		i++;
	}
	return (options3(av, opt));
}

int		options3(char *av, t_opt *opt)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 't')
			opt->sort = 't';
		if (av[i] == 'S')
			opt->sort = 'S';
		if (av[i] == 's')
			opt->s = 1;
		if (av[i] == 'R')
			opt->R = 1;
		i++;
	}
	return (1);
}