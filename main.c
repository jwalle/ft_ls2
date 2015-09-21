/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 13:36:45 by jwalle            #+#    #+#             */
/*   Updated: 2015/07/12 14:03:36 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	choose_print(t_list *list, t_opt *opt, char *av)
{
	if (list)
	{
		if (ft_strstr(av, "/dev") || ft_strstr(av, "/dev/"))
		{
			if (opt->l)
					print_dev(list, opt);
			else
				print_simple(list, opt);
		}
		else if (opt->R) 
		{
			if (opt->l)
				print_l(list, opt);
			else
				print_simple(list, opt);
		}
		else
		{
			if (opt->l)
				print_l(list, opt);
			else
				print_simple(list, opt);
		}
	}
}

void	choose_prog(char *av, t_opt *opt)
{
	t_list			*list;
	DIR				*dir;
	struct dirent	*dp;
	struct stat		filestat;

	list = NULL;
	lstat(av, &filestat);
	if (!(dir = opendir(av)) && lstat(av, &filestat))
	{
		fail_open_directory(av);
		return ;
	}
	if (S_ISDIR(filestat.st_mode))
	{
		while ((dp = readdir(dir)))
			list = ft_lst_push(list, stock_info(av, dir, dp));
		closedir(dir);
	}
	else
		print_file(av, opt);
	merge_sort(&list, opt);
	choose_print(list, opt, av);
	destroy(list);
}

int		ft_parse(char *av, t_opt *opt)
{
	if (av[0] == '-' && !opt->end)
	{
		options(av, opt);
		return (1);
	}
	return (0);
}

void	ft_parse_two(char **av, t_opt *opt, int j)
{
	if (opt->start)
		ft_putstr("\n");
	opt->end = 1;
	opt->start = 1;
	opt->file = 1;
	while (av)
	{
		if ((ac - i) != 1)
			print_folder(av);
		choose_prog(av, opt);
		av++;
	}
}

void	opt_init(t_opt *opt)
{
	opt->sort = 'd';
	opt->dft = 0;
	opt->end = 0;
	opt->l = 0;
	opt->R = 0;
	opt->a = 0;
	opt->r = 0;
	opt->A = 0;
	opt->d = 0;
	opt->g = 0;
	opt->G = 0;
	opt->i = 0;
	opt->n = 0;
	opt->s = 0;
	opt->v = 0;
	opt->file = 0;
	opt->start = 0;
}

int		main(int ac, char **av)
{
	t_opt	*opt;
	int		i;
	int		j;

	i = 1;
	j = 0;
	(void)ac;
	if ((opt = malloc(sizeof(t_opt))) == NULL)
		return (1);
	opt_init(opt);
	while (av[i])
		j += ft_parse(av[i++], opt, ac);
	ft_parse_two(av + j, opt, j);
	if (opt->file == 0)
		choose_prog(".", opt);
	free(opt);
	//while(1)
	//{}
	return(0);
}
