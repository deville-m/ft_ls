/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:01:56 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 21:27:01 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	one_arg(t_filelist *list, t_option option)
{
	if (!list)
		return ;
	if ((list->stat.st_mode & S_IFMT) == S_IFDIR)
	{
		dir_walk(list->path, option);
		del_list(&list);
	}
	else
		ft_ls_input(list, option);
}
