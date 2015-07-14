#include "ft_ls.h"

void	ft_putdevstr(int max, char *str)
{
	int i;

	i = 0;
	ft_putstr(str);
	while ((int)(ft_strlen(str) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(" ");
}

void	ft_putdevnbr(int max, int info)
{
	int	i;

	i = 0;
	ft_putnbr(info);
	while ((nblen(info) + i) < max)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar(' ');
}

void	sub_print_dev(t_info *current, t_opt *opt, t_len *len)
{
	if (opt->s)
		ft_putdevnbr(len->bsize_len, current->bsize);
	ft_putstr(current->perm);
	ft_putstr(" ");
	ft_putdevnbr(len->link_len, current->link);
	if (!opt->g)
		(!opt->n) ? ft_putdevstr(len->uid_len, current->uid) :
					ft_putdevnbr(len->uid_nb_len, current->uid_nb);
}

void	print_maj_min(t_info *current)
{
	int	maj_len;
	int	min_len;
	int i;
	
	i = 0;
	maj_len = nblen(current->major);
	min_len = nblen(current->minor);
	while (maj_len + i++ < 3)
		ft_putchar(' ');
	i = 0;
	ft_putnbr(current->major);
	ft_putstr(", ");
	while (min_len + i++ < 3)
		ft_putchar(' ');
	ft_putnbr(current->minor);
	ft_putchar(' ');
}

void		print_dev(t_list *list, t_opt *opt)
{
	t_len	*len;
	t_info	*current;

	len = get_len(list, opt);
	print_total(list, opt);
	while (list)
	{
		current = (t_info*)list->data;
		if (current->filename[0] != '.' || opt->a)
		{
			sub_print_dev(current, opt, len);
			if (!opt->G)
				(!opt->n) ? ft_putdevstr(len->gid_len, current->gid) :
							ft_putdevnbr(len->gid_nb_len, current->gid_nb);
			print_maj_min(current);
			ft_print_time(current->time);
			(!current->isdir) ? ft_putstr(current->filename) :
								ft_putstr_b(current->filename);
			if (current->islink)
			{
				ft_putstr(" -> ");
				ft_putstr(current->link_path);
			}
			ft_putchar('\n');
		}
		list = list->next;
	}
	free(len);
}