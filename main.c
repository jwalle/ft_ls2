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

void	print_simple(t_list *list, t_opt *opt)
{
	t_info *info;

	while (list)
	{
		info = (t_info*)list->data;
		if (info->filename[0] != '.' || opt->a)
		{
			if (opt->s)
				ft_putnnbr(0, info->bsize);
			if (info->filename[0] == '.')
				((info->isdir) && opt->a) ? ft_putstr_b(info->filename)
											: ft_putstr(info->filename);
			else
				(info->isdir) ? ft_putstr_b(info->filename)
								: ft_putstr(info->filename);
			ft_putstr("\n");
		}
		list = list->next;
	}
}

void	print_l(t_list *list, t_opt *opt)
{
	(void)opt;
	(void)list;
	printf("PLOP LLLLL");
}


void	choose_print(t_list *list, t_opt *opt)
{
	if (list)
	{
		if (opt->R)
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

	if ((dir = opendir(av)) == NULL)
	{
		fail_open_directory(av);
		return ;
	}
	while ((dp = readdir(dir)))
		list = ft_lst_push(list, stock_info(av, dir, dp));
	//merge_sort(list);
	choose_print(list, opt);
}

void	ft_parse(char **av, t_opt *opt)
{
	if (*av)
	{
		if (*av[0] == '-' && !opt->end)
		{
			options(*av, opt);
		}
		else
		{
			opt->end = 1;
			choose_prog(*av, opt);
		}
	}
	ft_parse(++av, opt);
}

void	opt_init(t_opt *opt)
{
	opt->sort = 0;
	opt->no_r = 0;
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
}

int		main(int ac, char **av)
{
	t_opt *opt;

	(void)ac;
	if ((opt = malloc(sizeof(opt))) == NULL)
		return (1);
	opt_init(opt);
	ft_parse(++av, opt);
	free(opt);
	return(0);
}
