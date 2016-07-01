/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 15:07:08 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/01 15:36:57 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *cmd;
	char *ls;
	char *ft_ls;
	cmd = av[1];

	ls = strdup("ls ");
	ls = strdup("./ft_ls ");
	realloc(ls, sizeof(char) * (4 + strlen(cmd)));
	realloc(ft_ls, sizeof(char) * (9 + strlen(cmd)));
	strcat(ls, cmd);
	strcat(ft_ls, cmd);
	system(ls);
	//puts("					==========================================");
	//system(ft_ls);
	return (0);
}
