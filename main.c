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


print_simple(t_info *info, t_opt *opt)
{
	t_list *list;

	list = 
	while (info != NULL)
	{
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
		info = info->next;
	}
}


void choose_print(t_info *info, t_opt *opt)
{
	if (info)
	{
		if (opt->R)
		{
			if (opt->l)
				print_l(info, opt);
			else
				print_simple(info, opt);
		}
		else
		{
			if (opt->l)
				print_l(info, opt);
			else
				print_simple(info, opt);
		}
	}
}

void choose_prog(char *av, t_opt *opt)
{
	t_list			*list;
	t_info			*info;
	DIR				*dir;
	struct dirent	*dp;

	if ((dir = opendir(av)) == NULL)
		return(fail_open_directory(av))
	info = (t_info*)list->data;
	while (dp = readdir(dir))
		info = ft_lst_push(info, stock_info(av, dir, dp));
	//merge_sort(list);
	choose_print(info, opt);
}

void ft_parse(char **av, t_opt *opt)
{
	if (av)
	{
		if (av[0] == '-' && !opt->end)
		{
			options(av, opt);
		}
		else
		{
			opt->end = 1;
			choose_prog(av, opt);
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

int main(int ac, char **av)
{
	t_opt *opt;

	if ((opt = malloc(sizeof(opt))) == NULL)
		return (1);
	opt_init(opt);
	ft_parse(++av, opt);
	free(opt);
	return(0);
}
