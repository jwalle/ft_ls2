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
# include "libft.h"
# include "ft_printf.h"

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

typedef	struct		s_folders
{
	char			*folder;
}					t_folders;

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
}					t_info;

typedef struct		s_opt
{
	char			**folders;
	char			**folder;
	int				f_num;
	char			sort;
	int				l;
	int				R;
	int				a;
	int				r;
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
	int				start;
	int				file;
}					t_opt;

void	print_stuff_two(void *ptr, size_t size, time_t time);
char	file_type(struct stat filestat);
char	*get_permission(struct stat filestat);
t_info	*stock_info(char *av, DIR *dir, struct dirent *dp);
void	print_simple(t_list *list, t_opt *opt);
void	print_l(t_list *list, t_opt *opt);
void	choose_print(t_list *list, t_opt *opt, char *av);
void	choose_prog(char *av, t_opt *opt);
int		ft_parse(char *av, t_opt *opt);
void	opt_init(t_opt *opt, int ac);
int		fail_open_directory(char *str);
int		error(char c);
int		options(char *av, t_opt *opt);
int		options2(char *av, t_opt *opt);
int		options3(char *av, t_opt *opt);
char	*correct_path(char *s1, char *s2);
void	ft_putstr_b(char *str);
void	ft_putnnbr(int max, int info);
void	ft_putnstr(int max, char *str);
int		nblen(int len);
void	destroy(t_list *list);
void 	destroy_info(void *data);
t_len	*get_len(t_list *list, t_opt *opt);
void	print_folder(char *str);
void	merge_sort(t_list **ref, t_opt *opt);
t_list	*merge(t_list *a, t_list *b);
t_list	*merge_r(t_list *a, t_list *b);
void	split(t_list *source, t_list **front, t_list **back);
t_list	*merge_time_r(t_list *a, t_list *b);
t_list	*merge_time(t_list *a, t_list *b);
t_list	*merge_size_r(t_list *a, t_list *b);
t_list	*merge_size(t_list *a, t_list *b);
void	print_dev(t_list *list, t_opt *opt);
void	print_total(t_list *list, t_opt *opt);
void	ft_print_time(time_t timefile);
void	print_file(char *av, t_opt *opt);
void	parse_recursive(t_opt *opt);
int		as_right(char *av);
void	print_noright(char *av);
void	destroy_folders(t_list *list_fold);


# endif