/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 13:44:08 by jwalle            #+#    #+#             */
/*   Updated: 2015/07/12 13:45:34 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>		//PRINTF A RETIRER
# include "libtf.h"

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\x1b[31m"
# define OPTIONS "l,R,a,r,t,A,d,g,G,i,n,S,v,s,1,-"


typedef	struct		s_len
{
	int				name_len;
	int				link_len;
	int				uid_len;
	int				uid_nb_len;
	int				gid_len;
	int				gid_nb_len;
	int				size_len;
	int				bsize_len;
	int				maj_len;
	int				min_len;
}					t_len;

typedef struct		s_info
{
	char			*filename;
	dev_t			device;
	int				isdir;
	int				islink;
	char			*perm;
	int				link;
	char			*link_path;
	char			*uid;
	int				uid_nb;
	char			*gid;
	int				gid_nb;
	int				size;
	int				bsize;
	time_t			time;
	int				major;
	int				minor;
	t_len			*len;
	//struct element	*next;
}					t_info;

typedef struct		s_opt
{
	int				sort;
	int				l;
	int				R;
	int				a;
	int				r;
	int				no_r;
	int				A;
	int				d;
	int				g;
	int				G;
	int				i;
	int				n;
	int				s;
	int				v;
	int				dft;
	int 			end;
}					t_opt;