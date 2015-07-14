#include "ft_ls.h"

t_list	*merge_size(t_list *a, t_list *b)
{
	t_list *result;
	t_info *info_a;
	t_info *info_b;

	if (!a)
		return (b);
	if (!b)
		return (a);
	info_a = (t_info*)a->data;
	info_b = (t_info*)b->data;
	if (info_a->size > info_b->size)
	{
		result = a;
		result->next = merge_size(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_size(a, b->next);
	}
	return (result);
}

t_list	*merge_size_r(t_list *a, t_list *b)
{
	t_list *result;
	t_info *info_a;
	t_info *info_b;

	if (!a)
		return (b);
	if (!b)
		return (a);
	info_a = (t_info*)a->data;
	info_b = (t_info*)b->data;
	if (info_a->size < info_b->size)
	{
		result = a;
		result->next = merge_size_r(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_size_r(a, b->next);
	}
	return (result);
}

t_list	*merge_time(t_list *a, t_list *b)
{
	t_list *result;
	t_info *info_a;
	t_info *info_b;

	if (!a)
		return (b);
	if (!b)
		return (a);
	info_a = (t_info*)a->data;
	info_b = (t_info*)b->data;
	if (info_a->time > info_b->time)
	{
		result = a;
		result->next = merge_time(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_time(a, b->next);
	}
	return (result);
}

t_list	*merge_time_r(t_list *a, t_list *b)
{
	t_list *result;
	t_info *info_a;
	t_info *info_b;

	if (!a)
		return (b);
	if (!b)
		return (a);
	info_a = (t_info*)a->data;
	info_b = (t_info*)b->data;
	if (info_a->time < info_b->time)
	{
		result = a;
		result->next = merge_time_r(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_time_r(a, b->next);
	}
	return (result);
}