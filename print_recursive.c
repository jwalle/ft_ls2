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

void	print_recursive(t_opt *opt, t_list *list_fold)
{
	int 			i;
	DIR				*dir;
	struct dirent	*dp;
	t_list			*list;
	t_folders		*current;

	i = 0;
	list = NULL;
	while (list_fold)
	{
		current = (t_folders *)list_fold->data;
		if (i > 0)
			ft_putstr("\n");
		print_folder(current->folder);
		dir = opendir(current->folder);
		while ((dp = readdir(dir)))
			list = ft_lst_push(list, stock_info(current->folder, dir, dp));
		closedir(dir);
		merge_sort(&list, opt);
		choose_print(list, opt, current->folder);
		destroy(list);
		list = NULL;
		list_fold = list_fold->next;
		i++;
	}
	destroy_folders(list_fold);
}

t_folders	*stk_lst_fold(char *path)
{
	t_folders	*new;

	if (!(new = malloc(sizeof(t_folders))))
		return (NULL);
	new->folder = ft_strdup(path);
	return(new);
}


t_list	*stock_folders(t_opt *opt, char *av, t_list *list_fold)
{
	struct dirent	*dp;
	DIR				*dir;
	char			*path;

	dir = opendir(av);
	while ((dp = readdir(dir)))
	{
		if (dp->d_name[0] != '.' && ft_strcmp(dp->d_name, "..") && is_folder(dp->d_name, av))
		{
			path = correct_path(av, dp->d_name);
			list_fold = ft_lst_push(list_fold, stk_lst_fold(path));
			stock_folders(opt, path, list_fold);
		}
	}
	closedir(dir);
	return(list_fold);
}

void	parse_recursive(t_opt *opt)
{
	int			i;
	t_list	*list_fold;

	i = 0;
	list_fold = NULL;
	if (opt->f_num == 0)
	{
		print_recursive(opt, list_fold);
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
		list_fold = ft_lst_push(list_fold, stk_lst_fold(opt->folder[i]));
		list_fold = stock_folders(opt, opt->folder[i], list_fold);
		free(opt->folder[i]);
		i++;
	}
	print_recursive(opt, list_fold);
}
