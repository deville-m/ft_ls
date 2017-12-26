/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:41:28 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 21:04:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include "ft_ls.h"
#include "ft_printf.h"
#include "libft.h"

void		print_long(t_filelist *file, t_maxlen max)
{
	t_longformat lformat;

	lformat = file->lformat;
	ft_printf("%s  %*s %-*s  %-*s  %*s %*s %s",
				lformat.permission,
				max.nlink, lformat.nlink,
				max.uid, lformat.uid,
				max.gid, lformat.gid,
				max.size, lformat.size,
				max.date, lformat.date,
				file->basename);
	if ((file->stat.st_mode & S_IFMT) == S_IFLNK)
		ft_printf(" -> %s", lformat.link);
	free(lformat.nlink);
	free(lformat.uid);
	free(lformat.gid);
	free(lformat.size);
	write(1, "\n", 1);
}
