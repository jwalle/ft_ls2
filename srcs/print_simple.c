#include "ft_ls.h"

void	print_simple(t_list *list, t_opt *opt)
{
	t_info *info;

	while (list)
	{
		info = (t_info*)list->data;
		if (info->filename[0] != '.' || opt->a)
		{
			if (opt->s)
				ft_putnnbr(0, info->bsize);
			if (info->filename[0] == '.')
				((info->isdir) && opt->a) ? ft_putstr_b(info->filename)
											: ft_putstr(info->filename);
			else
				(info->isdir) ? ft_putstr_b	(info->filename)
								: ft_putstr(info->filename);
			ft_putstr("\n");
		}
		list = list->next;
	}
}