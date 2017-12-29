/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:12:49 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/29 15:13:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_printf.h"

int			g_optopt = '?';
int			g_optind = 1;
int			g_opterr = 1;

int		ft_getopt(int argc, char *const argv[], const char *optstring)
{
	static char	*place = "";
	char		*tmp;

	if (!*place)
	{
		if (g_optind >= argc || *(place = argv[g_optind]) != '-'
			|| *(place + 1) == '\0')
			return (-1);
		if (*place == '-' && *++place == '-')
		{
			place = "";
			g_optind += 1;
			return (-1);
		}
	}
	g_optopt = *place++;
	if (!*place)
		++g_optind;
	if (!(tmp = ft_strchr(optstring, g_optopt)))
	{
		if (g_opterr && !tmp)
			ft_fprintf(2, "ls : illegal option -- %c\n", g_optopt);
		return ('?');
	}
	return (g_optopt);
}
