/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_walk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:04:39 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 19:29:13 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_ls.h"
#include "libft.h"

void	dir_walk(char *path, t_option option)
{
	DIR				*dp;
	struct dirent	*dir;
	t_filelist		*list;

	if (!path)
		return ;
	if (!(dp = opendir(path)))
		return (ls_err(ft_basename(path)));
	list = NULL;
	while ((dir = readdir(dp)) != NULL)
	{
		if (path[0] == '/' && !path[1])
			path++;
		if (option.a || dir->d_name[0] != '.')
			add_back(&list, new_elem(ft_strnjoin(3, path, "/", dir->d_name)));
	}
	if (closedir(dp) < 0)
		return (ls_err(path));
	ft_ls(list, option);
}
