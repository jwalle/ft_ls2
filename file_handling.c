/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 16:05:55 by jwalle            #+#    #+#             */
/*   Updated: 2015/07/12 16:06:06 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			as_right(char *av)
{
	struct stat	filestat;
	DIR			*dir;

	if (lstat(av, &filestat) || (dir = opendir(av)) == NULL) 
	{
		return (0);
	}
	closedir(dir);
	return (1);
}

char		*correct_path(char *s1, char *s2)
{
	char	*str;
	char 	*tmp;

	if (strcmp(s1, "/dev"))
	{
		tmp = ft_strjoin(s1, "/");
		str = ft_strjoin(tmp,s2);
		free(tmp);
		return (str);
	}
	return (s1);
}

int		fail_open_directory(char *str)
{
	ft_putstr("ft_ls: cannot access ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
	return (0);
}
