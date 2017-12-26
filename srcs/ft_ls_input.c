/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:01:13 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 19:46:20 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "ft_printf.h"

static t_maxlen		get_max(t_longformat *lformat)
{
	static t_maxlen	max;
	size_t			tmp;

	if (!lformat)
		ft_bzero(&max, sizeof(t_maxlen));
	else
	{
		if (lformat->nlink && (tmp = ft_strlen(lformat->nlink)) > max.nlink)
			max.nlink = tmp;
		if (lformat->uid && (tmp = ft_strlen(lformat->uid)) > max.uid)
			max.uid = tmp;
		if (lformat->gid && (tmp = ft_strlen(lformat->gid)) > max.gid)
			max.gid = tmp;
		if (lformat->size && (tmp = ft_strlen(lformat->size)) > max.size)
			max.size = tmp;
		if (max.date != 12 && (tmp = ft_strlen(lformat->date)) > max.date)
			max.date = tmp;
	}
	return (max);
}

static t_maxlen		prepare_long_file(t_filelist *list, t_option option)
{
	t_filelist	*curr;
	t_maxlen	len;

	curr = list;
	get_max(NULL);
	prepare_file(curr, option);
	len = get_max(&curr->lformat);
	while (curr->next != list)
	{
		curr = curr->next;
		prepare_file(curr, option);
		len = get_max(&curr->lformat);
	}
	return (len);
}

static inline void	iterate_dir(t_filelist *dirs, t_option option)
{
	while (dirs)
	{
		if (option.rec
			&& ft_strcmp(dirs->basename, ".") != 0
			&& ft_strcmp(dirs->basename, "..") != 0)
		{
			ft_printf("\n%s:\n", dirs->path);
			dir_walk(dirs->path, option);
		}
		del_link(&dirs);
	}
}

void				ft_ls_input(t_filelist *list, t_option option)
{
	t_filelist	*curr;
	t_filelist	*files;
	t_filelist	*dirs;
	t_maxlen	max;

	if (!list)
		return ;
	sort_filelist(&list, option);
	if (option.l)
		max = prepare_long_file(list, option);
	files = NULL;
	dirs = NULL;
	while (list)
	{
		if (option.r)
			r_rotate(&list);
		curr = pop_elem(&list);
		print_file(curr, option, max);
		((curr->stat.st_mode & S_IFMT) == S_IFDIR) ? add_back(&dirs, curr) :
			add_elem(&files, curr);
	}
	del_list(&files);
	iterate_dir(dirs, option);
}
