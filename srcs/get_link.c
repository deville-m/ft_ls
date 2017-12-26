/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:56:31 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 21:04:05 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_ls.h"

void	get_link(t_filelist *file)
{
	int tmp;

	if ((file->stat.st_mode & S_IFMT) == S_IFLNK)
	{
		tmp = readlink(file->path, file->lformat.link, MAXLNKSIZE);
		if (tmp < 0)
		{
			file->lformat.link[0] = '\0';
			return (ls_err(file->path));
		}
		else
			file->lformat.link[tmp] = '\0';
	}
}
