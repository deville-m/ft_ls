/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:01:13 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 17:32:58 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "ft_printf.h"

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

void				ft_ls(t_filelist *list, t_option option)
{
	t_filelist	*curr;
	t_filelist	*files;
	t_filelist	*dirs;
	t_maxlen	max;

	if (!list)
		return ;
	sort_filelist(&list, option);
	if (option.l)
		max = prepare_long(list, option);
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
