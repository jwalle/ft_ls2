/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 16:06:14 by jwalle            #+#    #+#             */
/*   Updated: 2015/07/12 16:06:17 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	file_type(struct stat filestat)
{
	char c;

	if (S_ISDIR(filestat.st_mode))
		c = 'd';
	else if (S_ISBLK(filestat.st_mode))
		c = 'b';
	else if (S_ISCHR(filestat.st_mode))
		c = 'c';
	else if (S_ISLNK(filestat.st_mode))
		c = 'l';
	else if (S_ISFIFO(filestat.st_mode))
		c = 'p';
	else if (S_ISSOCK(filestat.st_mode))
		c = 's';
	else
		c = '-';
	return (c);
}

void	get_permission(struct stat filestat, t_info *current)
{
	char *str;

	str = ft_strnew(11);
	str[0] = file_type(filestat);
	str[1] = (filestat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (filestat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (filestat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (filestat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (filestat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (filestat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (filestat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (filestat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (filestat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = 0;
	current->perm = ft_strdup(str);
	free(str);
}

t_info	stock_info(char *av, DIR *dir, struct dirent *dp)
{
	t_info			*new;
	struct stat		filestat;
	struct passwd	pwd;
	struct group	*grp;

	if (!(new = malloc(sizeof(t_info))))
		return (NULL);
	new->filename =ft_strdup(dp->d_name);
	lstat(correct_path(str, dp->d_name), &filestat);
	get_permission(filestat, new);
	new->isdir = S_ISDIR(filestat.st_mode);
	return (new);
}
