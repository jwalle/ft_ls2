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

t_info	*stock_dup(t_info *new, struct stat fs, struct dirent *dp, char *ph)
{
	struct passwd	*pwd;
	struct group	*grp;
	ssize_t			r;
	char			*buf;

	buf = ft_strnew(256);
	pwd = getpwuid(fs.st_uid);
	grp = getgrgid(fs.st_gid);
	new->filename = ft_strdup(dp->d_name);
	new->uid = ft_strdup(pwd->pw_name);
	new->gid = ft_strdup(grp->gr_name);
	get_permission(fs, new);
	if (new->islink)
	{

		r = readlink(ph, buf, sizeof(buf) - 1);
		buf[r] = 0;
		new->link_path = ft_strdup(buf);
	}
	else
		new->link_path = NULL;
	free(ph);
	free(buf);
	return (new);
}

void	min_maj(t_info *new)
{
	new->major = major(new->device);
	new->minor = minor(new->device);
}


t_info	*stock_info(char *av, DIR *dir, struct dirent *dp)
{
	t_info			*new;
	struct stat		filestat;
	char			*path;

	(void)dir;
	if (!(new = malloc(sizeof(t_info))))
		return (NULL);
	path = correct_path(av, dp->d_name);
	lstat(path, &filestat);
	new->isdir = S_ISDIR(filestat.st_mode);
	new->size = filestat.st_size;
	new->bsize = filestat.st_blocks / 2;
	new->link = filestat.st_nlink;
	new->uid_nb = filestat.st_uid;
	new->gid_nb = filestat.st_gid;
	new->time = filestat.st_mtime;
	new->device = filestat.st_rdev;
	new->islink = S_ISLNK(filestat.st_mode);
	min_maj(new);
	return (stock_dup(new, filestat, dp, path));
}
