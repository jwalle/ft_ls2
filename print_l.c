#include "ft_ls.h"

void	ft_print_time(time_t timefile)
{
	char	*str;
	int		i;
	time_t	current;

	str = ctime(&timefile);
	current = time(NULL);
	if (current - timefile < 0 || current - timefile >= 15552000)
	{
		i = ft_strlen(str) - 1;
		str[i] = 0;
		while (str[i] != ' ')
			--i;
		write(1, str + 4, 7);
		ft_putstr(str + i);
	}
	else
		write(1, str + 4, ft_strlen(str) - 13);
	ft_putchar(' ');
}

void	print_total(t_list *list, t_opt *opt)
{
	int		total;
	t_info	*current;

	total = 0;
	current = NULL;
	while (list)
	{
		current = (t_info*)list->data;
		if (current->filename[0] != '.' || opt->a)
		{
			total = total + current->bsize;
		}
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(2 * total);
	ft_putchar('\n');
}

void	sub_print_l(t_info	*current, t_opt *opt, t_len *len)
{
	if (opt->s)
		ft_putnnbr(len->bsize_len, current->bsize);
	ft_putstr(current->perm);
	ft_putstr(" ");
	ft_putnnbr(len->link_len, current->link);
	if (!opt->g)
		(!opt->n) ? ft_putnstr(len->uid_len, current->uid) :
					ft_putnnbr(len->uid_nb_len, current->uid_nb);
	ft_putchar(' ');
}

void		print_l(t_list *list, t_opt *opt)
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
			sub_print_l(current, opt, len);
			if (!opt->G)
				(!opt->n) ? ft_putnstr(len->gid_len, current->gid) :
							ft_putnnbr(len->gid_nb_len, current->gid_nb);
			ft_putchar(' ');
			ft_putnnbr(len->size_len, current->size);
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
