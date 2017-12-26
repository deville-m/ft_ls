/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_filelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 09:28:34 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 18:03:29 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

static intmax_t		namecmp(t_filelist *f1, t_filelist *f2)
{
	return (ft_strcmp(f1->basename, f2->basename));
}

static intmax_t		mtimecmp(t_filelist *f1, t_filelist *f2)
{
	intmax_t res;

	if (!(res = f2->stat.st_mtimespec.tv_sec - f1->stat.st_mtimespec.tv_sec))
		return (namecmp(f1, f2));
	return (res);
}

static intmax_t		atimecmp(t_filelist *f1, t_filelist *f2)
{
	intmax_t res;

	if (!(res = f2->stat.st_atimespec.tv_sec - f1->stat.st_atimespec.tv_sec))
		return (namecmp(f1, f2));
	return (res);
}

static inline void	repair_links(t_filelist **head)
{
	t_filelist *curr;
	t_filelist *prev;

	curr = *head;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
		curr->prev = prev;
	}
	(*head)->prev = curr;
	curr->next = *head;
}

void				sort_filelist(t_filelist **head, t_option option)
{
	if (!head || !*head || (*head)->next == *head || option.f)
		return ;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
	if (option.t)
	{
		if (option.u)
			merge_sort(head, atimecmp);
		else
			merge_sort(head, mtimecmp);
	}
	else
		merge_sort(head, namecmp);
	repair_links(head);
}
