/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:51:53 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/28 17:09:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <time.h>
#include <unistd.h>
#include "ft_ls.h"
#include "libft.h"

static void	get_date(t_filelist *file, t_option option, char *res)
{
	time_t	curr_time;
	time_t	file_time;
	char	*time_char;

	curr_time = time(NULL);
	if (option.u)
	{
		file_time = file->stat.st_atimespec.tv_sec;
		if (!(time_char = ctime(&file->stat.st_atimespec.tv_sec)))
			return ;
	}
	else
	{
		file_time = file->stat.st_mtimespec.tv_sec;
		if (!(time_char = ctime(&file->stat.st_mtimespec.tv_sec)))
			return ;
	}
	if (curr_time - file_time < 15778800)
		*(ft_stpncpy(res, time_char + 4, 12)) = '\0';
	else
	{
		ft_stpncpy(res, time_char + 4, 7);
		*(ft_stpncpy(res + 7, time_char + 19, 5)) = '\0';
	}
}

static void	get_exec(mode_t mode, char *tmp, mode_t exec, mode_t field)
{
	if (mode & field)
		*tmp = (mode & exec) ? 's' : 'S';
	else
		*tmp = (mode & exec) ? 'x' : '-';
}

static void	get_permissions(mode_t mode, char *tmp)
{
	*tmp++ = (mode & S_IRUSR) ? 'r' : '-';
	*tmp++ = (mode & S_IWUSR) ? 'w' : '-';
	get_exec(mode, tmp++, S_IXUSR, S_ISUID);
	*tmp++ = (mode & S_IRGRP) ? 'r' : '-';
	*tmp++ = (mode & S_IWGRP) ? 'w' : '-';
	get_exec(mode, tmp++, S_IXGRP, S_ISGID);
	*tmp++ = (mode & S_IROTH) ? 'r' : '-';
	*tmp++ = (mode & S_IWOTH) ? 'w' : '-';
	if (mode & S_IXOTH)
		*tmp++ = (mode & S_ISVTX) ? 't' : 'x';
	else
		*tmp++ = (mode & S_ISVTX) ? 'T' : '-';
	*tmp = '\0';
}

static void	get_mode(mode_t mode, char *tmp)
{
	mode_t	tmpmode;

	tmpmode = mode & S_IFMT;
	if (tmpmode == S_IFIFO)
		*tmp = 'p';
	else if (tmpmode == S_IFCHR)
		*tmp = 'c';
	else if (tmpmode == S_IFDIR)
		*tmp = 'd';
	else if (tmpmode == S_IFBLK)
		*tmp = 'b';
	else if (tmpmode == S_IFLNK)
		*tmp = 'l';
	else if (tmpmode == S_IFSOCK)
		*tmp = 's';
	else
		*tmp = '-';
	get_permissions(mode, tmp + 1);
}

void		prepare_file(t_filelist *file, t_option option)
{
	struct passwd	*tmp;
	struct group	*tmp2;

	get_mode(file->stat.st_mode, file->lformat.permission);
	get_date(file, option, file->lformat.date);
	file->lformat.nlink = ft_utoa(file->stat.st_nlink);
	(option.n || !(tmp = getpwuid(file->stat.st_uid))) ?
		(file->lformat.uid = ft_utoa(file->stat.st_uid))
		: (file->lformat.uid = ft_strdup(tmp->pw_name));
	(option.n || !(tmp2 = getgrgid(file->stat.st_gid))) ?
		(file->lformat.gid = ft_utoa(file->stat.st_gid))
		: (file->lformat.gid = ft_strdup(tmp2->gr_name));
	get_link(file);
	get_size(file);
}
