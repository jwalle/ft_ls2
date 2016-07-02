#include "ft_ls.h"

void destroy_info(void *data)
{
	t_info *info;

	info = (t_info*)data;
	ft_strdel(&info->filename);
	ft_strdel(&info->perm);
	ft_strdel(&info->uid);
	ft_strdel(&info->gid);
	if (info->islink)
		ft_strdel(&info->link_path);
	free(data);
	data = NULL;
}

void destroy(t_list *list)
{
	if (list)
	{
		ft_lst_foreach(list, destroy_info);
		ft_lst_rec_free(list);
	}
}

void	destroy_folders_two(void *data)
{
	t_folders	*current;

	current = (t_folders*)data;
	ft_strdel(&current->folder);
	free(data);
	data = NULL;
}

void	destroy_folders(t_list *list_fold)
{
	if (list_fold)
	{
		ft_lst_foreach(list_fold, destroy_folders_two);
		ft_lst_rec_free(list_fold);
	}
}
