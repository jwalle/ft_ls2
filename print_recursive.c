/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 18:42:11 by jwalle            #+#    #+#             */
/*   Updated: 2015/09/24 18:42:14 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_folder(char *folder, char *av)
{
	struct stat		filestat;
	char			*path;

	path = correct_path(av, folder);
	lstat(path, &filestat);
	if (S_ISDIR(filestat.st_mode) != 0)
		return (1);
	return (0);
}

void	print_recursive(t_opt *opt, char *folder)
{
	t_list			*list;
	DIR				*dir;
	struct dirent	*dp;
	struct stat		filestat;

	list = NULL;
	lstat(folder, &filestat);
	if (!(dir = opendir(folder)) && lstat(folder, &filestat))
	{
		fail_open_directory(folder);
		return ;
	}
	if (S_ISDIR(filestat.st_mode))
	{
		while ((dp = readdir(dir)))
		{
			list = ft_lst_push(list, stock_info(folder, dir, dp));
			if (is_folder(dp->d_name, folder))
			print_recursive(opt, dp->d_name);
		}

		closedir(dir);
	}
	else
		print_file(folder, opt);
	merge_sort(&list, opt);
	choose_print(list, opt, folder);
	destroy(list);	
}

/*
void	single_recursive(t_opt *opt)
{

}
*/

void	parse_recursive(t_opt *opt)
{
	static int i;

	i = 0;
	if (opt->f_num == 0)
	{
		print_recursive(opt, ".");
		return ;
	}
	while (i < opt->f_num)
	{
		if (opt->start)
			ft_putstr("\n");
		opt->end = 1;
		opt->start = 1;
		if (opt->f_num > 1 && i > 1)
			print_folder(opt->folder[i]);
		print_recursive(opt, opt->folder[i]);
		free(opt->folder[i]);
		i++;
		
	}
}