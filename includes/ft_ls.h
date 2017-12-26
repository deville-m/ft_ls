/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:37:24 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 19:27:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <string.h>
# include <time.h>
# include <dirent.h>
# include <sys/xattr.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <unistd.h>

# define MAXLNKSIZE 1024

typedef struct			s_maxlen
{
	size_t nlink;
	size_t uid;
	size_t gid;
	size_t size;
	size_t date;
}						t_maxlen;

typedef struct			s_longformat
{
	char			permission[11];
	char			*nlink;
	char			*uid;
	char			*gid;
	char			*size;
	char			date[13];
	char			link[MAXLNKSIZE];
}						t_longformat;

typedef struct			s_filelist
{
	char				*path;
	char				*basename;
	struct stat			stat;
	struct s_longformat	lformat;
	struct s_filelist	*prev;
	struct s_filelist	*next;
}						t_filelist;

typedef struct			s_option
{
	unsigned int		l: 1;
	unsigned int		rec: 1;
	unsigned int		a: 1;
	unsigned int		r: 1;
	unsigned int		t: 1;
	unsigned int		one_line: 1;
	unsigned int		i: 1;
	unsigned int		f: 1;
	unsigned int		m: 1;
	unsigned int		n: 1;
	unsigned int		u: 1;
}						t_option;

int						parse_option(int argc, char **argv, t_option *option);
t_filelist				*parse_arg(int optind,
								int argc,
								char *argv[],
								t_option option);
t_filelist				*new_elem(char *path);
void					add_elem(t_filelist **head, t_filelist *elem);
void					add_back(t_filelist **head, t_filelist *elem);
void					del_list(t_filelist **head);
void					del_link(t_filelist **head);
t_filelist				*pop_elem(t_filelist **head);
void					rotate(t_filelist **head);
void					r_rotate(t_filelist **head);
void					print_list(const int fd, t_filelist *head);
void					dir_walk(char *path, t_option option);
void					ft_ls(t_filelist *list, t_option option);
void					ft_ls_input(t_filelist *list, t_option option);
void					ls_err(const char *file);
void					one_arg(t_filelist *list, t_option option);
void					multiple_arg(t_filelist *list, t_option option);
void					print_file(
							t_filelist *list,
							t_option option,
							t_maxlen max);
void					print_long(t_filelist *list, t_maxlen max);
t_maxlen				prepare_long(t_filelist *list, t_option option);
void					prepare_file(t_filelist *file, t_option option);
void					get_link(t_filelist *file);
void					get_size(t_filelist *file);
void					sort_filelist(t_filelist **head, t_option option);
void					merge_sort(
							t_filelist **head,
							intmax_t (*cmp)(t_filelist *f1, t_filelist *f2));

#endif
