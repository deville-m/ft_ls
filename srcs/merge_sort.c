/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 09:47:06 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 17:21:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filelist	*merge(
					t_filelist *a,
					t_filelist *b,
					intmax_t (*cmp)(t_filelist *f1, t_filelist *f2))
{
	t_filelist *head;

	if (!b)
		return (a);
	else if (!a)
		return (b);
	if (cmp(a, b) < 0)
	{
		head = a;
		head->next = merge(a->next, b, cmp);
	}
	else
	{
		head = b;
		head->next = merge(a, b->next, cmp);
	}
	return (head);
}

void		split(t_filelist *head, t_filelist **a, t_filelist **b)
{
	t_filelist *fast;
	t_filelist *slow;

	if (!head || head->next == NULL)
	{
		*a = head;
		*b = NULL;
		return ;
	}
	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

void		merge_sort(t_filelist **head,
				intmax_t (*cmp)(t_filelist *f1, t_filelist *f2))
{
	t_filelist *a;
	t_filelist *b;

	if (!head || !*head || !(*head)->next)
		return ;
	split(*head, &a, &b);
	merge_sort(&a, cmp);
	merge_sort(&b, cmp);
	*head = merge(a, b, cmp);
}
