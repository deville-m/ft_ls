/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:54:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/22 16:34:17 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include "ft_printf.h"

void		print_file(t_filelist *list, t_option option, t_maxlen max)
{
	if (option.i)
		ft_printf("%u ", list->stat.st_ino);
	if (option.m && list->next != list)
		ft_printf("%s, ", list->basename);
	else if (!option.m && option.l)
		print_long(list, max);
	else if (!option.one_line && list->next != list && ft_isatty(1))
		ft_printf("%s ", list->basename);
	else
		ft_printf("%s\n", list->basename);
}
