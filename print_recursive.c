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
	if (S_ISDIR(filestat.st_mode))
		return (1);
	return (0);
}

void	print_recursive(t_opt *opt)
{
	/*t_list			*list;
	DIR				*dir;
	struct dirent	*dp;
	struct stat		filestat;*/
	int i;

	i = 0;
	// list = NULL;
	while (opt->folders[i])
	{
		printf("FOLDERS = %s\n", opt->folders[i++]);
	}

/*	else
		print_file(folder, opt);
	merge_sort(&list, opt);
	choose_print(list, opt, folder);
	destroy(list);*/
}


void	stock_folders(t_opt *opt, char *folder,  char *av)
{
	static int	i = -1;
	struct dirent	*dp;
	//char		*folder;
	DIR				*dir;
	struct stat		filestat;

	if (av)
	{
		folder = correct_path(av, folder);
		printf("%s - %s\n", av , folder);
	}
	if (!(dir = opendir(folder)) && lstat(folder, &filestat))
	{
		fail_open_directory(folder);
		return ;
	}
	// if (S_ISDIR(filestat.st_mode))
	{
		while ((dp = readdir(dir)))
		{
			//list = ft_lst_push(list, stock_info(folder, dir, dp));
			if (dp->d_name[0] != '.' && ft_strcmp(dp->d_name, "..")
			&& is_folder(dp->d_name, folder))
			{
				i++;
				printf("PLOP = %s\n", dp->d_name);
				opt->folders[i] = ft_strdup(folder);
				stock_folders(opt, opt->folders[i], NULL);
			}
		}
		closedir(dir);
	}		
}

void	parse_recursive(t_opt *opt)
{
	int i;

	i = 0;
	opt->folders = (char **)malloc(10000);
	if (opt->f_num == 0)
	{
		print_recursive(opt);
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
		stock_folders(opt, opt->folder[i], NULL);
		free(opt->folder[i]);
		i++;
	}
	print_recursive(opt);
}
