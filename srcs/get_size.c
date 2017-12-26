/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:17:21 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 19:25:14 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		copy_nb(char *res, int *nlen, unsigned int mode)
{
	while (mode >= 10)
	{
		res[*nlen] = mode % 10 + '0';
		mode /= 10;
		*nlen -= 1;
	}
	res[*nlen] = mode + '0';
	*nlen -= 1;
}

static char		*get_rdev(t_filelist *file)
{
	char			*res;
	unsigned int	major;
	unsigned int	minor;
	int				nlen;

	major = file->stat.st_rdev >> 24;
	minor = file->stat.st_rdev & 0xFF;
	nlen = 8;
	if (!(res = (char *)malloc(sizeof(char) * (nlen + 1))))
	{
		file->lformat.size = NULL;
		return (NULL);
	}
	res[nlen--] = '\0';
	copy_nb(res, &nlen, minor);
	while (nlen > 3)
		res[nlen--] = ' ';
	res[nlen--] = ',';
	copy_nb(res, &nlen, major);
	while (nlen >= 0)
		res[nlen--] = ' ';
	return (res);
}

void			get_size(t_filelist *file)
{
	if ((file->stat.st_mode & S_IFMT) == S_IFCHR)
		file->lformat.size = get_rdev(file);
	else
		file->lformat.size = ft_utoa(file->stat.st_size);
}
