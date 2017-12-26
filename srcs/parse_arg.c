/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:30:51 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/26 19:44:07 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

static t_filelist	*new_arg(char *path,
							int f(const char *, struct stat *restrict buf))
{
	t_filelist *res;

	if (!path)
		return (NULL);
	if (!(res = (t_filelist *)malloc(sizeof(t_filelist))))
		return (NULL);
	if (f(path, &res->stat) < 0)
	{
		ls_err(path);
		free(path);
		free(res);
		return (NULL);
	}
	res->path = path;
	res->basename = path;
	res->next = res;
	res->prev = res;
	return (res);
}

t_filelist			*parse_arg(int optind,
							int argc,
							char *argv[],
							t_option option)
{
	t_filelist	*res;

	if (optind >= argc)
		return (new_elem(ft_strdup(".")));
	res = NULL;
	while (optind < argc)
	{
		if (option.l)
			add_elem(&res, new_arg(ft_strdup(argv[optind++]), lstat));
		else
			add_elem(&res, new_arg(ft_strdup(argv[optind++]), stat));
	}
	return (res);
}
