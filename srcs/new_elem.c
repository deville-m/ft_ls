/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 11:52:07 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/21 12:47:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

t_filelist			*new_elem(char *path)
{
	t_filelist *res;

	if (!path)
		return (NULL);
	if (!(res = (t_filelist *)malloc(sizeof(t_filelist))))
		return (NULL);
	if (lstat(path, &res->stat) < 0)
	{
		ls_err(path);
		free(path);
		free(res);
		return (NULL);
	}
	res->path = path;
	res->basename = ft_basename(path);
	res->next = res;
	res->prev = res;
	return (res);
}
