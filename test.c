/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 15:07:08 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/01 16:57:05 by jwalle           ###   ########.fr       */
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

	ls = calloc(100, 100);
	ft_ls = calloc(100, 100);
	ls = strcpy(ls, "ls ");
	ft_ls = strcpy(ft_ls, "./ft_ls ");
	//ft_ls = strdup("./ft_ls ");
	//realloc(ls, sizeof(char) * 100);
	//realloc(ft_ls, sizeof(char) * 100);
	strcat(ls, cmd);
	strcat(ft_ls, cmd);
	strcat(ls, " > t1.txt");
	strcat(ft_ls," > t2.txt");
	system(ls);
	system(ft_ls);
	system("diff t1.txt t2.txt");
	puts("	==========================================");
	return (0);
}
