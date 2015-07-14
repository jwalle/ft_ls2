#include "ft_ls.h"

void	merge_sort(t_list **ref, t_opt *opt)
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *ref;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a, opt);
	merge_sort(&b, opt);
	printf("merge sort : %d\n", opt->r);
	if (opt->sort == 't')
		*ref = (opt->r) ? (merge_time_r(a, b)) : (merge_time(a, b));
	else if (opt->sort == 'S')
		*ref = (opt->r) ? (merge_size_r(a, b)) : (merge_size(a, b));
	else if (opt->sort == 'd')
		*ref = (opt->r) ? (merge_r(a, b)) : (merge(a, b));
}

t_list	*merge(t_list *a, t_list *b)
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
	if (ft_strcmp(info_a->filename, info_b->filename) < 0)
	{
		result = a;
		result->next = merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge(a, b->next);
	}
	return (result);
}

t_list	*merge_r(t_list *a, t_list *b)
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
	if (ft_strcmp(info_a->filename, info_b->filename) > 0)
	{
		result = a;
		result->next = merge_r(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_r(a, b->next);
	}
	return (result);
}

void	split(t_list *source, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	if (!source || !source->next)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}