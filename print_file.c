#include "ft_ls.h"

void	sub_print_file(struct stat filestat, t_opt *opt)
{
	char			*perm;
	struct passwd	*pwd;

	pwd = getpwuid(filestat.st_uid);
	if (opt->s)
		ft_putnbr(filestat.st_blocks / 2);
	perm = get_permission(filestat);
	ft_putstr(perm);
	ft_putstr(" ");
	ft_putnbr(filestat.st_nlink);
	ft_putstr(" ");
	if (!opt->g)
		(!opt->n) ? ft_putstr(pwd->pw_name) :
					ft_putnbr(filestat.st_uid);
					ft_putstr(" ");
	free(perm);
}

void		print_file(char *av, t_opt *opt)
{
	struct stat		filestat;
	struct group	*grp;
	char			*buf;
	ssize_t			r;

	buf = NULL;
	lstat(av, &filestat);
	grp = getgrgid(filestat.st_gid);
	sub_print_file(filestat, opt);
	if (!opt->G)
		(!opt->n) ? ft_putstr(grp->gr_name) :
					ft_putnbr(filestat.st_gid);
	ft_putnbr(filestat.st_size);
	ft_print_time(filestat.st_mtime);
	ft_putstr(av);
	if (S_ISLNK(filestat.st_mode))
	{
		buf = ft_strnew(256);
		r = readlink(av, buf, sizeof(buf));
		buf[r] = 0;
		ft_putstr(" -> ");
		ft_putstr(buf);
		free(buf);
	}
	ft_putchar('\n');
}