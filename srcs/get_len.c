#include "ft_ls.h"


int			check_len_nb(int n, int max)
{
	int	i;

	i = nblen(n);
	if (i > max)
		return (i);
	return (max);
}

int			check_len_str(char *str, int max)
{
	int i;

	i = ft_strlen(str);
	if (i > max)
		return (i);
	return (max);
}


void	set_size_zero(t_len *size)
{
	size->size_len = 0;
	size->link_len = 0;
	size->uid_len = 0;
	size->gid_len = 0;
	size->name_len = 0;
	size->bsize_len = 0;
	size->uid_nb_len = 0;
	size->gid_nb_len = 0;
	size->maj_len = 0;
	size->min_len = 0;

}

t_len		*get_len(t_list *list, t_opt *opt)
{
	t_len 	*size;
	t_info	*current;

	size = malloc(sizeof(t_len));
	set_size_zero(size);
	while (list)
	{
		current = (t_info*)list->data;
		if (current->filename[0] != '.' || opt->a)
		{
			size->link_len = check_len_nb(current->link, size->link_len);
			size->gid_len = check_len_str(current->gid, size->gid_len);
			size->uid_len = check_len_str(current->uid, size->uid_len);
			size->size_len = check_len_nb(current->size, size->size_len);
			size->name_len = check_len_str(current->filename, size->name_len);
			size->bsize_len = check_len_nb(current->bsize, size->bsize_len);
			size->uid_nb_len = check_len_nb(current->uid_nb, size->uid_nb_len);
			size->gid_nb_len = check_len_nb(current->gid_nb, size->gid_nb_len);
			size->min_len = check_len_nb(current->minor, size->min_len);
			size->maj_len = check_len_nb(current->major, size->maj_len);
		}
		list = list->next;
	}
	return (size);
}