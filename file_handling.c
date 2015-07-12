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

int		fail_open_directory(char *str)
{
	ft_putstr("ft_ls: cannot access ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
	return (NULL);
}
