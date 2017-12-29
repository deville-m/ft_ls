/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:03:12 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/29 11:49:56 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"
#include "libft.h"

static t_maxlen	get_max(t_longformat *lformat)
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

t_maxlen		prepare_long(t_filelist *list, t_option option)
{
	size_t		total;
	t_filelist	*curr;
	t_maxlen	len;

	curr = list;
	get_max(NULL);
	prepare_file(curr, option);
	len = get_max(&curr->lformat);
	total = curr->stat.st_blocks;
	while (curr->next != list)
	{
		curr = curr->next;
		prepare_file(curr, option);
		len = get_max(&curr->lformat);
		total += curr->stat.st_blocks;
	}
	ft_printf("total %zu\n", total);
	return (len);
}
