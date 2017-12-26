/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:32:32 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 17:29:26 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "ft_printf.h"
#include "libft.h"

static inline void	iterate_dir(
		t_filelist *dirs,
		t_filelist *files,
		t_option option)
{
	if (dirs && !files)
	{
		ft_printf("%s:\n", dirs->path);
		dir_walk(dirs->path, option);
		del_link(&dirs);
	}
	while (dirs)
	{
		ft_printf("\n%s:\n", dirs->path);
		dir_walk(dirs->path, option);
		del_link(&dirs);
	}
}

void				multiple_arg(t_filelist *list, t_option option)
{
	t_filelist *files;
	t_filelist *dirs;
	t_filelist *curr;

	if (!list)
		return ;
	files = NULL;
	dirs = NULL;
	while (list)
	{
		if (option.r)
			r_rotate(&list);
		curr = pop_elem(&list);
		if ((curr->stat.st_mode & S_IFMT) == S_IFDIR)
			add_back(&dirs, curr);
		else
			add_back(&files, curr);
		curr = curr->next;
	}
	ft_ls_input(files, option);
	sort_filelist(&list, option);
	iterate_dir(dirs, files, option);
}
